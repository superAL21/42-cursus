import argparse
import json
from .utils.io_utils import load_json, save_json

def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--input",
        type=str,
        default="data/input/function_calling_tests.json",
        help="Path to input prompts file",
    ) 

    parser.add_argument(
        "--output",
        type=str,
        default="data/output/function_calling_results.json",
        help="Path to output results file",
    )

    parser.add_argument(
        "--functions_definition",
        type=str,
        default="data/input/functions_definition.json",
        help="Path to functions schema file"
    )
    return parser

def process_prompts(input_data, functions_def) -> dict:
    try:
        if not isinstance(input_data, list):
            raise TypeError("input data must be a list")
        if not isinstance(functions_def, list):
            raise TypeError("functions_def must be a list")
    except:
        return "EXIT"
    results = []
    for item in input_data:
        data_processed = functions_def(item)
        results.append(data_processed)
    return {"results": results}

def main() -> None:
    parser = build_parser()
    args = parser.parse_args()
    try:
        input_data = load_json(args.input)
        functions_def = load_json(args.functions_definition)

        result = {
        "ok": True,
        "input_type": type(input_data).__name__,
        "functions_type": type(functions_def).__name__,
        }
        
        save_json(args.output, result)

    except FileNotFoundError as e:
        print(f"File not found: {e.filename}")
    except json.JSONDecodeError as e:
        print(f"Invalid JSON in {e.doc}: line {e.lineno}, column {e.colno}")
    except OSError as e:
        print(f"I/O error: {e}")




if __name__ == "__main__":
    main()