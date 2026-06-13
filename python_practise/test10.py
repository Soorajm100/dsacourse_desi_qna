import requests
from bs4 import BeautifulSoup


def decode_secret_message(doc_url: str):
    response = requests.get(doc_url)
    response.raise_for_status()

    soup = BeautifulSoup(response.text, "html.parser")

    rows = soup.find_all("tr")

    points = []
    max_x = 0
    max_y = 0

    for row in rows[1:]:
        cols = row.find_all("td")

        if len(cols) < 3:
            continue

        x = int(cols[0].get_text(strip=True))
        char = cols[1].get_text(strip=True)
        y = int(cols[2].get_text(strip=True))

        points.append((x, y, char))

        max_x = max(max_x, x)
        max_y = max(max_y, y)

    grid = [[" " for _ in range(max_x + 1)] for _ in range(max_y + 1)]

    for x, y, char in points:
        grid[y][x] = char

    for row in reversed(grid):
        print("".join(row))


decode_string = input("Enter the URL of the Google Doc: ")
decode_secret_message(decode_string)