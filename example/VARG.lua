local function fn1(aa, bb, cc, ...)
        local argc = select('#', ...)
        local argv = {...}
end

fn1(1, 2, 3,    4, 5, 6, 7, 8)

--[[
% luajit -b -L example/VARG.lua
-- BYTECODE -- VARG.lua:1-4
KGC    0    "select"
KGC    1    "#"
0001     [2]    GGET     3   0      ; "select"
0002     [2]    KSTR     5   1      ; "#"
0003     [2]    VARG     6   0   3
0004     [2]    CALLM    3   2   1
0005     [3]    TNEW     4   3
0006     [3]    VARG     5   0   3
0007     [3]    TSETM    5   0      ; 1
0008     [4]    RET0     0   1

-- BYTECODE -- VARG.lua:0-29
KGC    0    VARG.lua:1
0001     [4]    FNEW     0   0      ; VARG.lua:1
0002     [6]    MOV      1   0
0003     [6]    KSHORT   3   1
0004     [6]    KSHORT   4   2
0005     [6]    KSHORT   5   3
0006     [6]    KSHORT   6   4
0007     [6]    KSHORT   7   5
0008     [6]    KSHORT   8   6
0009     [6]    KSHORT   9   7
0010     [6]    KSHORT  10   8
0011     [6]    CALL     1   1   9
0012     [6]    RET0     0   1

]]