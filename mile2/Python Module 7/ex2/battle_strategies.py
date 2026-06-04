from abc import ABC, abstractmethod
from ex0.creatures import Creature
from ex1.capabilities import TransformCapability, HealCapability
from typing import cast


class InvalidStrategyError(Exception):
    pass


class BattleStrategy(ABC):
    @abstractmethod
    def act(self, creature: Creature) -> str:
        pass

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, Creature)

    def act(self, creature: Creature) -> str:
        if self.is_valid(creature):
            return creature.attack()
        else:
            raise InvalidStrategyError(f"Invalid Creature '{creature._name}'"
                                       f" for this aggresive strategy")


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature) -> bool:
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> str:
        if self.is_valid(creature):
            casted_creature = cast(TransformCapability, creature)
            res1 = casted_creature.transform()
            res2 = creature.attack()
            res3 = casted_creature.revert()
            return (f"{res1}\n{res2}\n{res3}")
        else:
            raise InvalidStrategyError(f"Invalid Creature '{creature._name}'"
                                       f" for this agressive strategy")


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> str:
        if self.is_valid(creature):
            casted_creature = cast(HealCapability, creature)
            res1 = creature.attack()
            res2 = casted_creature.heal()
            return (f"{res1}\n{res2}")
        else:
            raise InvalidStrategyError(f"Invalid Creature '{creature._name}'"
                                       f" for this defensive strategy")
