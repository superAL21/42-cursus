def hidenp(small: str, big: str) -> bool:
	if not small:
		return True
	i = 0
	limit = len(small)
	for c in big:
		if c == small[i]:
			i += 1
			if i == limit:
				return True

	return False