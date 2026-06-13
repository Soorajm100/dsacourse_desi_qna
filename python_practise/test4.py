import requests




def filter_rating_movies(movies, genre):
    res =[ ]

    for movie in  movies  : 
        if genre in  movie['genres'] :
            res.append(movie)
    return res



def  get_api_details( genre :str):
    res =[]
    final_arr =[]
    for i in  range(1,2): 
        response  =  requests.get(f"https://api.tvmaze.com/shows?page={i}")
        res.extend(filter_rating_movies(response.json() , genre))
    res.sort(key = lambda x : (-(x.get('rating',{}).get('average') or 0) , x.get('name','') or ""))
    for movie in res : 
        final_arr.append(movie['name'])
    return final_arr


print(get_api_details(genre="Action"))


