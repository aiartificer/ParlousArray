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
