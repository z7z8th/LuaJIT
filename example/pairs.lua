-- how pairs work

local t = {111, 222, 333, a = 'aaa', b = 'bbb'}

print(pairs(t))

local next_fn, state, ctrl_k = pairs(t)

print("next_fn == next: ", next_fn == next)  -- true
print("state == t: ", state == t) -- true

local cnt = 0
while true do
    local v
    ctrl_k, v = next_fn(state, ctrl_k)
    if not ctrl_k then
        print("iter done")
        break
    end
    -- body
    print("[", ctrl_k, "] = ", v)
    cnt = cnt + 1
end
