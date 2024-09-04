name = io.read("*l")
space = string.find(name, ' ')
namelength = string.len(name)
firstname = string.sub(name, 1, space)
endname = string.sub(name, space + 1, namelength)
secondspace = string.find(endname, ' ')
secondname = string.sub(endname, 1, secondspace)
thirdname = string.sub(endname, secondspace + 1)

firstname = string.upper(string.sub(firstname, 1, 1)) .. string.lower(string.sub(firstname, 2))
secondname = string.upper(string.sub(secondname, 1, 1)) .. string.lower(string.sub(secondname, 2))
thirdname = string.upper(string.sub(thirdname, 1, 1)) .. string.lower(string.sub(thirdname, 2))

fullname = firstname .. secondname .. thirdname
print(fullname)
  
