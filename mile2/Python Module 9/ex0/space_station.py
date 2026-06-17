from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
from typing import Optional


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: Optional[str] = Field(default=None, max_length=200)


def main() -> None:
    print("\nSpace Station Data Validation")
    print("========================================")

    space_station = SpaceStation(
        station_id='LGW125',
        name='Titan Mining Outpost',
        crew_size=6,
        power_level=76.4,
        oxygen_level=95.5,
        last_maintenance=datetime(2023, 7, 11, 0, 0, 0),
        is_operational=True,
        notes=None
    )

    if space_station.is_operational:
        status = "Operational"
    else:
        status = "Inoperative"

    print("Valid station created:")
    print(f"ID: {space_station.station_id}")
    print(f"Name: {space_station.name}")
    print(f"Crew: {space_station.crew_size} people")
    print(f"Power: {space_station.power_level}%")
    print(f"Oxygen: {space_station.oxygen_level}%")
    print(f"Last maintenance: {space_station.last_maintenance}")
    print(f"Status: {status}")

    print("\n========================================")
    print("Expected validation error")
    try:
        invalid_station = SpaceStation(
            station_id='QCH189',
            name='Deep Space Observatory',
            crew_size=30,
            power_level=70.8,
            oxygen_level=88.1,
            last_maintenance=datetime(2023, 8, 24, 0, 0, 0),
            is_operational=False,
            notes='System diagnostics required'
        )
        print(f"{invalid_station}")

    except ValidationError as error:
        print(f"{error.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
