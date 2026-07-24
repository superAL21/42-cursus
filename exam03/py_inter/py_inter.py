def inter(s1: str, s2: str) -> str:
	result = ""
	for c in s1:
		if c not in result and c in s2:
			result += c

	return result
