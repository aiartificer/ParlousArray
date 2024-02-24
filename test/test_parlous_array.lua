--local parray = require("ParlousArray/ParlousArray")

function Test_Parlous_Array()
  print("Test_Parlous_Array")
  --local arr = parray.new_int_array(10, 8)
  local arr = parlous_array.new_int_array(10, 8)
  print("length of arr: "..#arr)
  arr[0] = 1
  print("arr[0] = "..arr[0])
  if pcall(function () print(arr[11]) end) then
    print("Expected index out of bounds error and didn't get one")
  else
    print("Got expected index out of bounds error")
  end
end

print("> Test_Parlous_Array <")
Test_Parlous_Array()
