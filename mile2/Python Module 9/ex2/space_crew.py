from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime


class Rank(str, Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def mission_validator(self) -> "SpaceMission":
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        has_leader = False
        total_experience = 0
        for member in self.crew:
            if not member.is_active:
                raise ValueError("All crew members must be active")

            if member.rank in (Rank.CAPTAIN, Rank.COMMANDER):
                has_leader = True

            if member.years_experience >= 5:
                total_experience += 1

        if not has_leader:
            raise ValueError("Must have at least one Commander or Captain")

        if self.duration_days > 365:
            percent = total_experience / len(self.crew)
            if percent < 0.50:
                raise ValueError(r"Long missions need 50% experienced")

        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("======================================")
    members = [
        CrewMember(
            member_id="CM001",
            name="Sarah Williams",
            rank=Rank.CAPTAIN,
            age=43,
            specialization="Mission Command",
            years_experience=19,
            is_active=True
        ),
        CrewMember(
            member_id="CM002",
            name="James Hernandez",
            rank=Rank.CAPTAIN,
            age=43,
            specialization="Pilot",
            years_experience=30,
            is_active=True
        ),
        CrewMember(
            member_id="CM003",
            name="Anna Jones",
            rank=Rank.CADET,
            age=35,
            specialization="Communications",
            years_experience=15,
            is_active=True
        ),
        CrewMember(
            member_id="CM004",
            name="David Smith",
            rank=Rank.COMMANDER,
            age=27,
            specialization="Security",
            years_experience=15,
            is_active=True
        ),
        CrewMember(
            member_id="CM005",
            name="Maria Jones",
            rank=Rank.CADET,
            age=55,
            specialization="Research",
            years_experience=30,
            is_active=True
        )
    ]

    space_mission = SpaceMission(
        mission_id="M2024_TITAN",
        mission_name="Solar Observatory Research Mission",
        destination="Solar Observatory",
        launch_date=datetime(2024, 3, 30, 0, 0, 0),
        duration_days=451,
        crew=members,
        mission_status="planned",
        budget_millions=2208.1
    )

    print("Valid mission created:")
    print(f"Mission: {space_mission.mission_name}")
    print(f"ID: {space_mission.mission_id}")
    print(f"Destination: {space_mission.destination}")
    print(f"Duration: {space_mission.duration_days} days")
    print(f"Buget: ${space_mission.budget_millions}M")
    print(f"Crew size: {len(members)}")
    print("Crew members:")
    for member in space_mission.crew:
        print(f"- {member.name} ({member.rank.value})"
              f" - {member.specialization}")

    print("\n======================================")
    print("Expected validation error:")

    try:
        invalid_mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime(2024, 1, 15, 0, 30, 0),
            duration_days=900,
            crew=[
                CrewMember(
                    member_id="CM003",
                    name="Anna Jones",
                    rank=Rank.LIEUTENANT,
                    age=35,
                    specialization="CNavigation",
                    years_experience=10,
                    is_active=True
                )
            ],
            mission_status="planned",
            budget_millions=2500.0
        )
        print(f"{invalid_mission}")

    except ValidationError as error:
        print(f"{error.errors()[0]['msg'].removeprefix('Value error, ')}")


if __name__ == "__main__":
    main()
