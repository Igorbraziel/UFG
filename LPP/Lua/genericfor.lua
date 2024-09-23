t = {
    name = "Igor",
    age = 19
}

for k, v in pairs(t) do
    print(k, v)
end

a = {}

a[1] = 10
a[2] = 'nada'
a[3] = true
a[4] = 7
a[5] = false

for k, v in ipairs(a) do
    print(k,v)
end