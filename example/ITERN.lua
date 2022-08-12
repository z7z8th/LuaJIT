local t = { a = 1, b = 2, c = 3 }
local cnt=0

for k, v in pairs(t) do
    cnt = cnt + 1
end

--[[
% luajit -b -L example/ITERN.lua
-- BYTECODE -- ITERN.lua:0-8
KGC    0    table
KGC    1    "pairs"
0001     [1]    TDUP     0   0
0002     [2]    KSHORT   1   0
0003     [4]    GGET     2   1      ; "pairs"
0004     [4]    MOV      4   0
0005     [4]    CALL     2   4   2
0006     [4]    ISNEXT   5 => 0008
0007     [5] => ADDVN    1   1   0  ; 1
0008     [4] => ITERN    5   3   3
0009     [4]    ITERL    5 => 0007
0010     [6]    RET0     0   1
]]