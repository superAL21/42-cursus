def string_permutation_checker(s1: str, s2: str) -> bool:
	if len(s1) != len(s2):
		return False

	for c in s1:
		if s1.count(c) != s2.count(c):
			return False

	return True