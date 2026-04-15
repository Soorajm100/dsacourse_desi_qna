#!/usr/bin/env python3
"""Competitive programming / algorithm contest template.

Usage:
  python python_template.py < input.txt

Edit `solve()` for each problem.
"""

from __future__ import annotations

import sys
import threading
from typing import List, Tuple, Iterator, Any


# Fast IO helpers -------------------------------------------------------------

_DATA = sys.stdin.buffer.read().split()
_it: Iterator[bytes] = iter(_DATA)


def read_token() -> bytes:
    """Read the next whitespace-separated token as bytes."""
    return next(_it)


def read_str() -> str:
    """Read the next token as a string."""
    return read_token().decode()


def read_int() -> int:
    """Read the next token as an int."""
    return int(read_token())


def read_ints(n: int) -> List[int]:
    """Read exactly `n` integers."""
    return [read_int() for _ in range(n)]


def read_ints_until_eof() -> List[int]:
    """Read all remaining tokens as ints."""
    return [int(x) for x in _DATA]


def read_strs(n: int) -> List[str]:
    """Read exactly `n` strings."""
    return [read_str() for _ in range(n)]


def read_line() -> str:
    """Read the rest of the current line (not used for token-based parsing)."""
    return sys.stdin.readline().rstrip("\n")


# Problem solver -------------------------------------------------------------

def solve() -> None:
    """Main solution entry point.

    Replace the body of this function for each problem.
    """

    # Example usage of fast readers:
    # n = read_int()
    # arr = read_ints(n)
    # s = read_str()

    # TODO: implement problem logic here.
    # This example just echoes the input as integers.
    if not _DATA:
        return

    out: List[str] = []
    for token in _DATA:
        try:
            out.append(str(int(token)))
        except ValueError:
            out.append(token.decode())

    sys.stdout.write(" ".join(out))


def main() -> None:
    # Uncomment this line when your solution uses deep recursion.
    # threading.Thread(target=solve).start()
    solve()


if __name__ == "__main__":
    main()
