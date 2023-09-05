local function print_table(table)
	for key, value in pairs(table) do
		print(key, value)
	end
end

local location = {city ="kampala", country="Uganda"}
local info = {firstname= "farid", lastname="Matovu", location=location}
print_table(info)
print(type(location))


