--local parray = require("ParlousArray/ParlousArray")

function Setup_Int_PArray(length, type_size)
  local arr = parlous_array.new_int_array(length, type_size, 5)
  print("-- parlous_array -----------------------")
  for k,v in pairs(getmetatable(arr)) do print(k,v) end
  print("----------------------------------------")

  return arr
end

function Setup_Num_PArray(length, type_size)
  local arr = parlous_array.new_num_array(length, type_size, 5)
  print("-- parlous_array -----------------------")
  for k,v in pairs(getmetatable(arr)) do print(k,v) end
  print("----------------------------------------")

  return arr
end

function Test_Parlous_Int_Array_Meta()
  print("\n\nTest_Parlous_Array")
  local arr = Setup_Int_PArray(10, 8)

  -- Test length and index
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
  local arr = Setup_Int_PArray(10, 8)
  arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; arr[5] = 5;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  print("arr[0] = "..arr[0])
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  arr:map(function (x) return x+1 end)
  print("arr[0] = "..arr[0])
  assert(arr[0] == 11, "Expected arr[0]=11, actually arr[0]="..arr[0])
end

function Test_Parlous_Array_Foreach()
  print("\n\nTest_Parlous_Array_Foreach")
  local arr = Setup_Int_PArray(10, 8)
  arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; arr[5] = 5;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  print("arr[0] = "..arr[0])
  assert(arr[0] == 10, "Expected arr[0]=10, actually arr[0]="..arr[0])
  local sum = 0
  arr:foreach(function (x) sum = sum + x end)
  print("sum = "..sum)
  assert(sum == 55, "Expected sum=55, actually sum="..sum)
end

function Speed_Test_PArray_Map()
  print("\n\nSpeed_Test_PArray_Map")
  local ARR_SIZE = 100000000

  -- Initialize Lua table
  print("----------------------------------------")
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
  local parray = parlous_array.new_int_array(ARR_SIZE, 8, 5)
  print("Time tanspired building PArray table: "..os.time()-start_time)

  -- Run map on ParlousArray
  start_time = os.time()
  parray:map(function (x) return x/(x+1)*(x+2)/(x+3)*(x*4)/(x+5) end)
  print("Time tanspired running code on PArray table: "..os.time()-start_time)
  print("----------------------------------------")

  -- Run code on Lua table
  start_time = os.time()
  for i=1, ARR_SIZE do
    lua_table[i] = lua_table[i] + lua_table[i]
  end
  print("Time tanspired running addition code on Lua table: "..os.time()-start_time)

  -- Run map on ParlousArray
  parray = parlous_array.new_int_array(ARR_SIZE*25, 8, 5)
  start_time = os.time()
  parray = parray + parray
  print("Time tanspired running addition code on 25xPArray table: "..os.time()-start_time)

  -- Run map on ParlousArray
  parray = parlous_array.new_num_array(ARR_SIZE*15, 8, 5)
  start_time = os.time()
  parray = parray + parray
  print("Time tanspired running addition code on 15xPArray(num) table: "..os.time()-start_time)
  print("----------------------------------------")
end

function Test_Parlous_Num_Array_Meta()
  print("\n\nTest_Parlous_Num_Array")
  local arr = Setup_Num_PArray(10, 8)

  -- Test length and index
  print("length of arr: "..#arr)
  assert(#arr == 10, "Expected length of arr to be 10, actually "..#arr)
  arr[0] = 1.1
  assert(arr[0] == 1.1, "Expected arr[0]=1.1, actually arr[0]="..arr[0])
  print("arr[0] = "..arr[0])
  assert(arr[0] == 1.1, "Expected arr[0]=1.1, actually arr[0]="..arr[0])

  -- Test add
  local arrB = Setup_Num_PArray(10, 8)
  arr[1] = 1.1; arr[2] = 2.2; arr[3] = 3.3; arr[4] = 4.4; arr[5] = 5.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arrB[1] = 1.1; arrB[2] = 2.2; arrB[3] = 3.3; arrB[4] = 4.4; arrB[5] = 5.5;
  arrB[6] = 6.6; arrB[7] = 7.7; arrB[8] = 8.8; arrB[9] = 9.9; arrB[0] = 10.0;
  arr = arr + arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 6.6, "Expected arr[3]=6.6, actually arr[3]="..arr[3])

  -- Test error condition
  if pcall(function () print(arr[11]) end) then
    print("Expected index out of bounds error and didn't get one")
  else
    print("Got expected index out of bounds error")
  end
end

function Test_Parlous_Array_Add()
  print("\n\nTest_Parlous_Array_Add")

  -- Test add integers
  local arr = Setup_Int_PArray(10, 8)
  local arrB = Setup_Int_PArray(10, 8)
  arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; arr[5] = 5;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  arrB[1] = 1; arrB[2] = 2; arrB[3] = 3; arrB[4] = 4; arrB[5] = 5;
  arrB[6] = 6; arrB[7] = 7; arrB[8] = 8; arrB[9] = 9; arrB[0] = 10;
  arr = arr + arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 6, "Expected arr[3]=6, actually arr[3]="..arr[3])

  -- Test add numbers
  local arr = Setup_Num_PArray(10, 8)
  local arrB = Setup_Num_PArray(10, 8)
  arr[1] = 1.1; arr[2] = 2.2; arr[3] = 3.3; arr[4] = 4.4; arr[5] = 5.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arrB[1] = 1.1; arrB[2] = 2.2; arrB[3] = 3.3; arrB[4] = 4.4; arrB[5] = 5.5;
  arrB[6] = 6.6; arrB[7] = 7.7; arrB[8] = 8.8; arrB[9] = 9.9; arrB[0] = 10.0;
  arr = arr + arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 6.6, "Expected arr[3]=6.6, actually arr[3]="..arr[3])
end

function Test_Parlous_Array_Sub()
  print("\n\nTest_Parlous_Array_Sub")

  -- Test subtract integers
  local arr = Setup_Int_PArray(10, 8)
  local arrB = Setup_Int_PArray(10, 8)
  arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5; arr[5] = 6;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  arrB[1] = 1; arrB[2] = 2; arrB[3] = 3; arrB[4] = 4; arrB[5] = 5;
  arrB[6] = 6; arrB[7] = 7; arrB[8] = 8; arrB[9] = 9; arrB[0] = 10;
  arr = arr - arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 1, "Expected arr[3]=1, actually arr[3]="..arr[3])

  -- Test subtract numbers
  local arr = Setup_Num_PArray(10, 8)
  local arrB = Setup_Num_PArray(10, 8)
  arr[1] = 2.1; arr[2] = 3.2; arr[3] = 4.3; arr[4] = 5.4; arr[5] = 6.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arrB[1] = 1.1; arrB[2] = 2.2; arrB[3] = 3.3; arrB[4] = 4.4; arrB[5] = 5.5;
  arrB[6] = 6.6; arrB[7] = 7.7; arrB[8] = 8.8; arrB[9] = 9.9; arrB[0] = 10.0;
  arr = arr - arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 1.0, "Expected arr[3]=1.0, actually arr[3]="..arr[3])
end

function Test_Parlous_Array_Mult()
  print("\n\nTest_Parlous_Array_Mult")

  -- Test multiply integers
  local arr = Setup_Int_PArray(10, 8)
  local arrB = Setup_Int_PArray(10, 8)
  arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; arr[5] = 5;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  arrB[1] = 1; arrB[2] = 2; arrB[3] = 3; arrB[4] = 4; arrB[5] = 5;
  arrB[6] = 6; arrB[7] = 7; arrB[8] = 8; arrB[9] = 9; arrB[0] = 10;
  arr = arr*arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 9, "Expected arr[3]=9, actually arr[3]="..arr[3])

  -- Test multiply numbers
  local arr = Setup_Num_PArray(10, 8)
  local arrB = Setup_Num_PArray(10, 8)
  arr[1] = 1.1; arr[2] = 2.2; arr[3] = 3.3; arr[4] = 4.4; arr[5] = 5.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arrB[1] = 1.1; arrB[2] = 2.2; arrB[3] = 3.3; arrB[4] = 4.4; arrB[5] = 5.5;
  arrB[6] = 6.6; arrB[7] = 7.7; arrB[8] = 8.8; arrB[9] = 9.9; arrB[0] = 10.0;
  arr = arr*arrB;
  print("arr[3] = "..arr[3])
  assert(0.1 > arr[3] - 10.89, "Expected arr[3]=10.89, actually arr[3]="..arr[3])
end

function Test_Parlous_Array_Div()
  print("\n\nTest_Parlous_Array_Div")

  -- Test divide integers
  local arr = Setup_Int_PArray(10, 8)
  local arrB = Setup_Int_PArray(10, 8)
  arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5; arr[5] = 6;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  arrB[1] = 1; arrB[2] = 2; arrB[3] = 3; arrB[4] = 4; arrB[5] = 5;
  arrB[6] = 6; arrB[7] = 7; arrB[8] = 8; arrB[9] = 9; arrB[0] = 10;
  arr = arr/arrB;
  print("arr[3] = "..arr[3])
  assert(0.1 > arr[3] - 1.33, "Expected arr[3]=1.33, actually arr[3]="..arr[3])

  -- Test divide numbers
  local arr = Setup_Num_PArray(10, 8)
  local arrB = Setup_Num_PArray(10, 8)
  arr[1] = 2.1; arr[2] = 3.2; arr[3] = 4.3; arr[4] = 5.4; arr[5] = 6.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arrB[1] = 1.1; arrB[2] = 2.2; arrB[3] = 3.3; arrB[4] = 4.4; arrB[5] = 5.5;
  arrB[6] = 6.6; arrB[7] = 7.7; arrB[8] = 8.8; arrB[9] = 9.9; arrB[0] = 10.0;
  arr = arr/arrB;
  print("arr[3] = "..arr[3])
  assert(0.1 > arr[3] - 1.30, "Expected arr[3]=1.30, actually arr[3]="..arr[3])
end

function Test_Parlous_Array_Mod()
  print("\n\nTest_Parlous_Array_Mod")

  -- Test modulo integers
  local arr = Setup_Int_PArray(10, 8)
  local arrB = Setup_Int_PArray(10, 8)
  arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5; arr[5] = 6;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  arrB[1] = 1; arrB[2] = 2; arrB[3] = 3; arrB[4] = 4; arrB[5] = 5;
  arrB[6] = 6; arrB[7] = 7; arrB[8] = 8; arrB[9] = 9; arrB[0] = 10;
  arr = arr%arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 1, "Expected arr[3]=1.33, actually arr[3]="..arr[3])

  -- Test modulo numbers
  local arr = Setup_Num_PArray(10, 8)
  local arrB = Setup_Num_PArray(10, 8)
  arr[1] = 2.1; arr[2] = 3.2; arr[3] = 4.3; arr[4] = 5.4; arr[5] = 6.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arrB[1] = 1.1; arrB[2] = 2.2; arrB[3] = 3.3; arrB[4] = 4.4; arrB[5] = 5.5;
  arrB[6] = 6.6; arrB[7] = 7.7; arrB[8] = 8.8; arrB[9] = 9.9; arrB[0] = 10.0;
  arr = arr%arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 1, "Expected arr[3]=1.30, actually arr[3]="..arr[3])
end

function Test_Parlous_Array_Pow()
  print("\n\nTest_Parlous_Array_Pow")

  -- Test power integers
  local arr = Setup_Int_PArray(10, 8)
  local arrB = Setup_Int_PArray(10, 8)
  arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5; arr[5] = 6;
  arr[6] = 6; arr[7] = 7; arr[8] = 8; arr[9] = 9; arr[0] = 10;
  arrB[1] = 1; arrB[2] = 2; arrB[3] = 3; arrB[4] = 4; arrB[5] = 5;
  arrB[6] = 6; arrB[7] = 7; arrB[8] = 8; arrB[9] = 9; arrB[0] = 10;
  arr = arr^arrB;
  print("arr[3] = "..arr[3])
  assert(arr[3] == 64, "Expected arr[3]=1.33, actually arr[3]="..arr[3])

  -- Test power numbers
  local arr = Setup_Num_PArray(10, 8)
  local arrB = Setup_Num_PArray(10, 8)
  arr[1] = 2.1; arr[2] = 3.2; arr[3] = 4.3; arr[4] = 5.4; arr[5] = 6.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arrB[1] = 1.1; arrB[2] = 2.2; arrB[3] = 3.3; arrB[4] = 4.4; arrB[5] = 5.5;
  arrB[6] = 6.6; arrB[7] = 7.7; arrB[8] = 8.8; arrB[9] = 9.9; arrB[0] = 10.0;
  arr = arr^arrB;
  print("arr[3] = "..arr[3])
  assert(0.1 > arr[3] - 123.15, "Expected arr[3]=1.30, actually arr[3]="..arr[3])
end

function Test_Parlous_Array_Views()
  print("\n\nTest_Parlous_Array_Views")

  -- Test Views with width=5
  local arr = Setup_Int_PArray(20, 8)
  arr[1] = 2.1; arr[2] = 3.2; arr[3] = 4.3; arr[4] = 5.4; arr[5] = 6.5;
  arr[6] = 6.6; arr[7] = 7.7; arr[8] = 8.8; arr[9] = 9.9; arr[0] = 10.0;
  arr[11] = 2.1; arr[12] = 3.2; arr[13] = 4.3; arr[14] = 5.4; arr[15] = 6.5;
  arr[16] = 6.6; arr[17] = 7.7; arr[18] = 8.8; arr[19] = 9.9; arr[10] = 10.0;
  print("arr[12] = "..arr[12]);
  print("arr(2, 2) = "..arr(2, 2));
  assert(arr(2, 2) == arr[12], "Expected arr(2, 2)=3, actually arr(2, 2)="..arr(2, 2))
end

print("> Test_Parlous_Array <")
Test_Parlous_Int_Array_Meta()
Test_Parlous_Array_Map()
Test_Parlous_Array_Foreach()
Test_Parlous_Num_Array_Meta()
Test_Parlous_Array_Add()
Test_Parlous_Array_Sub()
Test_Parlous_Array_Mult()
Test_Parlous_Array_Div()
Test_Parlous_Array_Mod()
Test_Parlous_Array_Pow()
Test_Parlous_Array_Views()
Speed_Test_PArray_Map()
