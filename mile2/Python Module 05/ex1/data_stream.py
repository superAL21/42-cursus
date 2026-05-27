#!/usr/bin/env python3
from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._storage: list[str] = []
        self._current_rank: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._storage:
            return (0, "")
        data = self._storage.pop(0)
        self._current_rank += 1
        return (self._current_rank, data)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(
                isinstance(item, (int, float)) and not
                isinstance(item, bool) for item in data)
        return isinstance(data, (int, float)) and not isinstance(data, bool)

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")

        if isinstance(data, list):
            string_list = [str(item) for item in data]
            self._storage.extend(string_list)
        else:
            self._storage.append(str(data))


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        return isinstance(data, str)

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")

        if isinstance(data, list):
            self._storage.extend(data)
        else:
            self._storage.append(data)


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(
                isinstance(d, dict) and
                all(
                    isinstance(k, str) and
                    isinstance(v, str) for k, v in d.items()) for d in data)
        if isinstance(data, dict):
            return all(
                isinstance(k, str) and isinstance(v, str)
                for k, v in data.items())
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")

        if isinstance(data, list):
            strings_log = [str(d) for d in data]
            self._storage.extend(strings_log)
        else:
            self._storage.append(str(data))


class DataStream():
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for item in stream:
            processor_found = False
            for processor in self._processors:
                if processor.validate(item):
                    processor.ingest(item)
                    processor_found = True
                    break
            if not processor_found:
                print(f"Data Stream error -"
                      f" Can't process element in stream: {item}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        for proc in self._processors:
            nm = proc.__class__.__name__.replace("Processor", " Processor")
            total_items = proc._current_rank + len(proc._storage)
            remaining = len(proc._storage)
            print(f"{nm}: total {total_items}"
                  f" items processed, remaining {remaining} on processor")

        if not self._processors:
            print("No processor found, no data\n")


if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===\n")

    print("Initialize Data Stream...")
    data_stream = DataStream()
    data_stream.print_processors_stats()

    print("Registering Numeric Processor\n")
    numeric_proc = NumericProcessor()
    data_stream.register_processor(numeric_proc)

    batch = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {'log_level': 'WARNING',
             'log_message': 'Telnet access! Use ssh instead'},
            {'log_level': 'INFO',
             'log_message': 'User wil is connected'}],
        42,
        ['Hi', 'five']
        ]
    print(f"Send first batch of data on stream: {batch}")
    data_stream.process_stream(batch)
    data_stream.print_processors_stats()

    print("\nRegistering other data processors")
    text_proc = TextProcessor()
    data_stream.register_processor(text_proc)
    log_proc = LogProcessor()
    data_stream.register_processor(log_proc)
    print("Send the same batch again")
    data_stream.process_stream(batch)
    data_stream.print_processors_stats()

    print("\nConsume some elements from the data processors:"
          " Numeric 3, Text 2, Log 1")
    for _ in range(3):
        numeric_proc.output()
    for _ in range(2):
        text_proc.output()
    for _ in range(1):
        log_proc.output()
    data_stream.print_processors_stats()
