

import requests 

#   response  =  requests.get(f"https://api.tvmaze.com/shows?page={i}")


def filter_rating_movies(movies , genre):
    res = [] 

    for movie in  movies : 
        if genre  in  movie['genres'] : 
            res.append(movie)
    return res



def  get_api_details(genre :str ) : 
    res =[] 

    for  i in  range(1,2):
        response = requests.get(f"https://api.tvmaze.com/shows?page={i}")
        #print(response.json())
        res.extend(filter_rating_movies(response.json(), genre))

    res.sort(key = lambda  x : (-(x.get('rating', {}).get('average') or 0) , x.get('name') or ""))
    print(res)

    return res[0]['name'] if len(res) >=1  else  ""




print(get_api_details(genre="Action"))



    