--local parray = require("ParlousArray/ParlousArray")

function Test_Parlous_Array()
  print("Test_Parlous_Array")
  --local arr = parray.new_int_array(10, 8)
  local arr = parlous_array.new_int_array(10, 8)
  arr[0] = 1
  print("arr[0] = "..arr[0])
end

print("> Test_Parlous_Array <")
Test_Parlous_Array()
