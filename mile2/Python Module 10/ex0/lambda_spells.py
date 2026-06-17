def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(
        artifacts,
        key=lambda element: element['power'],
        reverse=True,
        )


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(
        filter(
            lambda mage: mage['power'] >= min_power,
            mages
        )
    )


def spell_transformer(spells: list[str]) -> list[str]:
    return list(
        map(
            lambda spell: f"* {spell} *",
            spells,
        )
    )


def mage_stats(mages: list[dict]) -> dict:
    strongest_mage = max(mages, key=lambda mage: mage['power'])
    pmax_result = strongest_mage['power']

    weakest_mage = min(mages, key=lambda mage: mage['power'])
    pmin_result = weakest_mage['power']

    power_list = [mage['power'] for mage in mages]
    average_result = round(sum(power_list) / len(mages), 2)

    return {
        "max_power": pmax_result,
        "min_power": pmin_result,
        "avg_power": average_result
    }


def main() -> None:
    artifacts = [
        {'name': 'Fire Staff', 'power': 111, 'type': 'armor'},
        {'name': 'Storm Crown', 'power': 70, 'type': 'accessory'},
        {'name': 'Lightning Rod', 'power': 83, 'type': 'relic'},
        {'name': 'Storm Crown', 'power': 102, 'type': 'focus'}
        ]
    mages = [
        {'name': 'Rowan', 'power': 58, 'element': 'earth'},
        {'name': 'Morgan', 'power': 62, 'element': 'shadow'},
        {'name': 'Sage', 'power': 57, 'element': 'earth'},
        {'name': 'Phoenix', 'power': 51, 'element': 'fire'},
        {'name': 'Luna', 'power': 64, 'element': 'light'}
        ]
    spells = ['lightning', 'heal', 'tornado', 'flash']

    print("\nTesting artifact sorter...")
    artifact_to_print = artifact_sorter(artifacts)
    for i in range(len(artifact_to_print) - 1):
        art1 = artifact_to_print[i]
        art2 = artifact_to_print[i + 1]
        print(
            f"{art1['name']} ({art1['power']} power) comes before"
            f"{art2['name']} ({art2['power']} power)"
        )

    print("\nTesting power filter...")
    filter_to_print = power_filter(mages, 60)
    for mage in filter_to_print:
        print(f"{mage['name']} ({mage['power']} power)")

    print("\nTesting spell transformer...")
    spells_to_print = spell_transformer(spells)
    for spell in spells_to_print:
        print(spell, end=" ")

    print()

    print("\nTesting mage stats...")
    statistics = mage_stats(mages)
    print(f" Max power: {statistics['max_power']}")
    print(f" Min power: {statistics['min_power']}")
    print(f" Average power: {statistics['avg_power']}")


if __name__ == "__main__":
    main()
