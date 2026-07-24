def number_base_converter(number: str, from_base: int, to_base: int) -> str:
	if not 2 <= from_base <= 36 and not 2 <= to_base <= 36:
		return "ERROR"

	try:
		decimal = int(number, from_base)
	except (TypeError, ValueError):
		return "ERROR"

	if decimal == 0:
		return "0"

	base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	result = ""
	while decimal > 0:
		result = base[decimal % to_base] + result
		decimal = decimal //  to_base

	return result
