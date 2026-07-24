def anagram(s1: str, s2: str) -> bool:
	cleans1 = ""
	cleans2 = ""
	for c in s1:
		if c.isalpha():
			cleans1 += c.lower()
	for c in s2:
		if c.isalpha():
			cleans2 +=  c.lower()

	if len(cleans1) != len(cleans2):
		return False

	for c in cleans1:
		if cleans1.count(c) != cleans2.count(c):
			return False

	return True
