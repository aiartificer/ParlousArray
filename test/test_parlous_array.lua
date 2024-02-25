--local parray = require("ParlousArray/ParlousArray")

function Setup_PArray()
  local arr = parlous_array.new_int_array(10, 8)
  print("-- parlous_array -----------------------")
  for k,v in pairs(getmetatable(arr)) do print(k,v) end
  print("----------------------------------------")

  return arr
end

function Test_Parlous_Array_Meta()
  print("\n\nTest_Parlous_Array")
  local arr = Setup_PArray()
  print("length of arr: "..#arr)
  assert(#arr == 10, "Expected length of arr to be 10, actually "..#arr)
  arr[0] = 1
  assert(arr[0] == 1, "Expected arr[0]=1, actually arr[0]="..arr[0])
  print("arr[0] = "..arr[0])
  assert(arr[0] == 1, "Expected arr[0]=1, actually arr[0]="..arr[0])

  -- Test error condition
  if pcall(function () print(arr[11]) end) then
    print("Expected index out of bounds error and didn't get one")
  else
    print("Got expected index out of bounds error")
  end
end

function Test_Parlous_Array_Map()
  print("\n\nTest_Parlous_Array_Map")
  local arr = Setup_PArray()
  arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; arr[5] = 5;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  print("arr[0] = "..arr[0])
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  arr:map(function (x) return x+1 end)
  print("arr[0] = "..arr[0])
  assert(arr[0] == 11, "Expected arr[0]=11, actually arr[0]="..arr[0])
end

print("> Test_Parlous_Array <")
Test_Parlous_Array_Meta()
Test_Parlous_Array_Map()
