# Native extension template
This template contains the basic setup for creation of a Defold native extension.

You can learn more about native extensions in the [official manual](https://www.defold.com/manuals/extensions/).

## Usage

Initialize a parlous array as shown below

```Lua
local int_arr = parlous_array.new_int_array(length, type_size, 5)
local num_arr = parlous_array.new_num_array(length, type_size, 5)
```
 ```
new_int_array(length, type_size, 5)
new_num_array(length, type_size, 5)
    length - Full length of the array
    type_size - Size of the type represented in bytes
    width - Size of a row if the array is 2D.  The length should be divisible by the given width.
```

To acces an element of the array

```Lua
int_arr[2]      -- Access the array as a 1D array
int_arr(2, 2)   -- Access the array as a 2D array
```

To iterate through the array using a function, use either map or foreach

```Lua
-- Iterates through the array itering each element by 1
int_arr:map(function (x) return x+1 end)

-- Sums the elements of the array and accumulates the results into sum
local sum = 0
int_arr:foreach(function (x) sum = sum + x end)
```

Can also get the length of the array in the standard Lua fashion.  The lenght provided will be the length input during creation and will not care about null values.

```Lua
length == #int_arr
```

Can also perform various standard math operations on the array

```Lua
local int_arr_B = parlous_array.new_int_array(length, type_size, 5)
-- Initialize the arrays with values here
int_arr = int_arr + int_arr_B   -- Sumes the elements of int_arr and int_arr_B and puts it into int_arr
```
