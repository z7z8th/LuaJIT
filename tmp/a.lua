local t1 = {
    [true] = "true",
    -- [nil] = "nil",
    [...] = "...",
    [function () return "anony function" end] = "function",
    [{1, 2, 3, [{1,2,3}] = "sub {1,2,3}"}] = "{1,2,3}",
    [1 + 2] = "binop",
    [-12] = "unop"
}

local i = 1
for k,v in pairs(t1) do
    print(i, ":", "[", k, "]    =>  ", v)
    i = i+1
end