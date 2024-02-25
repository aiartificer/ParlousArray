--local parray = require("ParlousArray/ParlousArray")

function Setup_PArray(length, type_size)
  local arr = parlous_array.new_int_array(length, type_size)
  print("-- parlous_array -----------------------")
  for k,v in pairs(getmetatable(arr)) do print(k,v) end
  print("----------------------------------------")

  return arr
end

function Test_Parlous_Array_Meta()
  print("\n\nTest_Parlous_Array")
  local arr = Setup_PArray(10, 8)

  -- Test length and index
  print("length of arr: "..#arr)
  assert(#arr == 10, "Expected length of arr to be 10, actually "..#arr)
  arr[0] = 1
  assert(arr[0] == 1, "Expected arr[0]=1, actually arr[0]="..arr[0])
  print("arr[0] = "..arr[0])
  assert(arr[0] == 1, "Expected arr[0]=1, actually arr[0]="..arr[0])

  -- Test add
  local arrB = Setup_PArray(10, 8)
  arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; arr[5] = 5;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  arrB[1] = 1; arrB[2] = 2; arrB[3] = 3; arrB[4] = 4; arrB[5] = 5;
  arrB[6] = 6; arrB[7] = 7; arrB[8] = 8; arrB[9] = 9; arrB[0] = 10;
  arr = arr + arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 6, "Expected arr[3]=6, actually arr[3]="..arr[3])

  -- Test error condition
  if pcall(function () print(arr[11]) end) then
    print("Expected index out of bounds error and didn't get one")
  else
    print("Got expected index out of bounds error")
  end
end

function Test_Parlous_Array_Map()
  print("\n\nTest_Parlous_Array_Map")
  local arr = Setup_PArray(10, 8)
  arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; arr[5] = 5;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  print("arr[0] = "..arr[0])
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  arr:map(function (x) return x+1 end)
  print("arr[0] = "..arr[0])
  assert(arr[0] == 11, "Expected arr[0]=11, actually arr[0]="..arr[0])
end

function Speed_Test_PArray_Map()
  print("\n\nSpeed_Test_PArray_Map")
  local ARR_SIZE = 100000000

  -- Initialize Lua table
  local start_time = os.time()
  local lua_table = {}
  for i=1, ARR_SIZE do
    lua_table[i] = 1
  end
  print("Time tanspired building table: "..os.time()-start_time)

  -- Run code on Lua table
  start_time = os.time()
  for i=1, ARR_SIZE do
    lua_table[i] = lua_table[i]/(lua_table[i]+1)*(lua_table[i]+2)/(lua_table[i]+3)*(lua_table[i]+4)/(lua_table[i]+5)
  end
  print("Time tanspired running code on table: "..os.time()-start_time)

  -- Initialize ParlousArray
  start_time = os.time()
  local parray = parlous_array.new_int_array(ARR_SIZE, 8)
  print("Time tanspired building PArray table: "..os.time()-start_time)

  -- Run map on ParlousArray
  start_time = os.time()
  parray:map(function (x) return x/(x+1)*(x+2)/(x+3)*(x*4)/(x+5) end)
  print("Time tanspired running code on PArray table: "..os.time()-start_time)

  -- Run code on Lua table
  start_time = os.time()
  for i=1, ARR_SIZE do
    lua_table[i] = lua_table[i] + lua_table[i]
  end
  print("Time tanspired running addition code on Lua table: "..os.time()-start_time)

  -- Run map on ParlousArray
  parray = parlous_array.new_int_array(ARR_SIZE*15, 8)
  start_time = os.time()
  parray = parray + parray
  print("Time tanspired running addition code on 15xPArray table: "..os.time()-start_time)
end


print("> Test_Parlous_Array <")
Test_Parlous_Array_Meta()
Test_Parlous_Array_Map()
Speed_Test_PArray_Map()
