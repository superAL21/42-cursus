from collections.abc import Callable


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP!"


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} damage!"


def spell_combiner(
        spell1: Callable, spell2: Callable
        ) -> Callable[[str, int], tuple[str, str]]:
    if not callable(spell1) or not callable(spell2):
        raise TypeError("Both spells must be a callable")

    def combined_spell(target: str, power: int) -> tuple[str, str]:
        res1 = spell1(target, power)
        res2 = spell2(target, power)
        return (res1, res2)
    return combined_spell


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    if not callable(base_spell):
        raise TypeError("The base spell must be callables")

    def amplified_power(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)

    return amplified_power


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    if not callable(condition) or not callable(spell):
        raise TypeError("Both spells must be callables")

    def conditional_spell(target: str, power: int) -> str:
        if condition(target, power) is True:
            return spell(target, power)
        else:
            return "Spell fizzled"

    return conditional_spell


def spell_sequence(spells: list[Callable]) -> Callable:
    if not all(callable(spell) for spell in spells):
        raise TypeError("All the spells in the sequence must be callables")

    def sequen_caster(target: str, power: int) -> list[str]:
        results = []

        for spell in spells:
            res = spell(target, power)
            results.append(res)
        return results

    return sequen_caster


def main():
    print("\nTesting spell combiner...")
    combo = spell_combiner(fireball, heal)
    res_fire, res_heal = combo("Dragon", 50)
    print(f"Combined spell result: {res_fire}, {res_heal}")

    print("\nTesting power amplifier...")
    result_base = fireball('Dragon', 10)
    ampli = power_amplifier(fireball, 3)
    result_ampli = ampli('Dragon', 10)
    print(f"Original: {result_base}, Amplified: {result_ampli}")

    print("\nTesting conditional caster...")
    secure_heal = conditional_caster(lambda _, power: power >= 20, heal)
    print(secure_heal("Goblin", 30))
    print(secure_heal("Wizard", 10))

    print("\nTesting spell sequence...")
    sequence = spell_sequence([fireball, heal, fireball])
    result_sequence = sequence('Wizard', 88)
    for spell in result_sequence:
        print(spell)


if __name__ == "__main__":
    main()
