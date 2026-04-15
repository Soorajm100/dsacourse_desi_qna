import requests


for i  in range(1,2) : 
    response = requests.get(f"https://api.tvmaze.com/shows?page={i}")
    print(response.json())


