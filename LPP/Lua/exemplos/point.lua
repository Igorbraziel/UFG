function Point(x, y)
    local state = {}
    local obj = {}

    state.x = x
    state.y = y

    obj.getX = function()
        return state.x
    end

    obj.getY = function()
        return state.y
    end

    obj.distance = function(p)
        return math.sqrt((p.getX() - obj.getX()) ^ 2 + (p.getY() - obj.getY()) ^ 2)
    end
    
    return obj
end

local p1 = Point(10, 20)
local p2 = Point(20, 30)
print(p1.getX())
print(p2.getY())
print(p1.distance(p2))

