local json = require 'cjson'

function f4(a, b)
	json.decode('{"a": 123, "b": "def" }')
	return a * b
end

function f2(i)
	local aaa = 4
	local bbb = 5
	return f3(i, aaa) + bbb
end

function f3(i)
	local ccc = 7
	local ddd = 8
	return f4(i, ccc) - ddd
end

function f1(i)
	if i%1000 == 0 then
		f2(i)
	else
		f3(i)
	end
end

cnt=tonumber(arg[1]) or 100000000
print("cnt ", cnt)
for i=0,cnt do
	f1(i)
end

