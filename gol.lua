-- game of life
function rule(table, x, y)
	amount = getAmount(table, 1, x, y, 1)
	currstate = getElement(table, x, y)
	--print("amount", amount)
	--print("currstate ", currstate)
	if currstate == 1 then		
		if amount == 2 or amount == 3 then -- 2 and 3 survive
			return 1
		else -- less than 2 or more than 3 die
			return 0
		end
	elseif currstate == 0 then
		if amount == 3 then
			return 1
		else
			return 0
		end
	end
end
