def py_bracket_validator(string: str) -> bool:
	stack = []
	pairs = {
		')': '(',
		']': '[',
		'}': '{'
	}

	for c in string:
		if c in "([{":
			stack.append(c)
		
		elif c in pairs:
			if not stack:
				return False
			
			last_open = stack.pop()

			if last_open != pairs[c]:
				return False

	return len(stack) == 0

print(py_bracket_validator("()"))