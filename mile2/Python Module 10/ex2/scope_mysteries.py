from collections.abc import Callable


def mage_counter() -> Callable:
    counter = 0

    def intern_counter() -> int:
        nonlocal counter
        counter += 1
        return counter

    return intern_counter


def spell_acumulator(initial_power: int) -> Callable:

    def intern_acumulator(num_to_add) -> int:
        nonlocal initial_power
        initial_power += num_to_add
        return initial_power

    return intern_acumulator


def enchantment_factory(enchantment_type: str) -> Callable:

    def enchantment_description(item_name: str) -> str:
        description: str = f"{enchantment_type} {item_name}"
        return description

    return enchantment_description


def memory_vault() -> dict[str, Callable]:
    private_boved = {}

    def intern_funct_to_save(key: str, value: str) -> None:
        private_boved[key] = value

    def inter_funct_to_recover(key: str) -> str:
        return private_boved.get(key, "Memory not found")

    return {
        "store": intern_funct_to_save,
        "recall": inter_funct_to_recover
    }


def main() -> None:

    print("\nTesting mage counter...")
    counter_a = mage_counter()
    print(f"counter_a call 1: {counter_a()}")
    print(f"counter_a call 2: {counter_a()}")
    counter_b = mage_counter()
    print(f"counter_b call 1: {counter_b()}")

    print("\nTesting spell accumulator...")
    accumulator = spell_acumulator(100)
    print(f"Base 100, add 20: {accumulator(20)}")
    print(f"Base 100, add 30: {accumulator(30)}")

    print("\nTesting enchantment factory...")
    creature_1 = enchantment_factory("Flaming")
    print(f"{creature_1('Sword')}")
    creature_2 = enchantment_factory("Frozen")
    print(f"{creature_2('Shield')}")

    print("\nTesting memory vault...")
    memory = memory_vault()
    print("Store 'secret' = 42")
    memory["store"]("secret", 42)
    print(f"Recall 'secret': {memory['recall']('secret')}")
    print(f"Recall 'unknown': {memory['recall']('unknown')}")


if __name__ == "__main__":
    main()
