from collections.abc import Callable
import functools
import operator
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0

    valid_operations: dict[str, Callable[[int, int], int]] = {
        'add': operator.add,
        'multiply': operator.mul,
        'max': max,
        'min': min
    }

    if operation not in valid_operations:
        raise ValueError(f"Unknown operation: {operation}")

    op_function = valid_operations[operation]

    return functools.reduce(op_function, spells)


def base_enchantment(power: int, element: str, target: str) -> str:
    return (

        f"[CRITICAL HIT] Weapon imbued with {element.upper()} "
        f"deals {power} elemental damage to {target}!"
    )


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:

    enchantment_fire = functools.partial(base_enchantment, 50, "fire")

    enchantment_water = functools.partial(base_enchantment, 50, "water")

    enchantment_ice = functools.partial(base_enchantment, 50, "ice")

    return {
        'fire': enchantment_fire,
        'water': enchantment_water,
        'ice':  enchantment_ice
        }


@functools.lru_cache
def memoized_fibonacci(n: int) -> int:
    if n <= 0:
        return 0
    elif n == 1:
        return 1

    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:

    @functools.singledispatch
    def spell_processor(spell: Any) -> str:
        raise TypeError("Unknown spell type")

    @spell_processor.register(int)
    def _(spell: int) -> str:
        return f"Damage spell: {spell} points!"

    @spell_processor.register(str)
    def _(spell: str) -> str:
        return f"Enchantment: {spell}"

    @spell_processor.register(list)
    def _(spell: list):
        return [spell_processor(item) for item in spell]

    return spell_processor


def main() -> None:

    print("\nTesting spell reducer...")
    sum = spell_reducer([10, 10, 10, 10, 10, 50], "add")
    print(f"Sum: {sum}")
    product = spell_reducer([3, 4, 2, 10, 10, 100], "multiply")
    print(f"Product: {product}")
    max = spell_reducer([34, 11, 6, 0, -2, 40], "max")
    print(f"Max: {max}")

    print("\nTesting partial enchanter...")
    enchantments = partial_enchanter(base_enchantment)
    enchantment_fire = enchantments['fire']
    result1 = enchantment_fire("Water monster")
    print(result1)
    enchantment_water = enchantments['water']
    result2 = enchantment_water("Fire Golem")
    print(result2)
    enchantment_ice = enchantments['ice']
    result3 = enchantment_ice("Gigant of fire")
    print(result3)

    print("\nTesting Memoized Fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(memoized_fibonacci.cache_info())
    print(f"Fib(15): {memoized_fibonacci(15)}")
    print(memoized_fibonacci.cache_info())

    print("\nTesting spell dispatcher...")
    cast = spell_dispatcher()

    print(cast(42))
    print(cast('fireball'))
    multi = [3.1415, 'snowball', 100]
    print("Multi-cast: 3 spells")
    try:
        for result in cast(multi):
            print(f"{result}")
    except Exception as error:
        print(f"{error}")


if __name__ == "__main__":
    main()
