from selenium import webdriver
import time
import requests
from bs4 import BeautifulSoup
from urllib.request import urlopen # library to perform action on urls 

driver = webdriver.Chrome() # using chrome 
driver.get("https://www.tiktok.com/@larrygao")
# add a delay in order to give the page to load 
time.sleep(1) # one second

### BELOW IS THE CODE to handle infinite Scroll Web Pages
scroll_pause_time = 1 # You can set your own pause time. My laptop is a bit slow so I use 1 sec
screen_height = driver.execute_script("return window.screen.height;")   # get the screen height of the web
i = 1

while True:
    # scroll one screen height each time
    driver.execute_script("window.scrollTo(0, {screen_height}*{i});".format(screen_height=screen_height, i=i))  
    i += 1
    time.sleep(scroll_pause_time)
    # update scroll height each time after scrolled, as the scroll height can change after we scrolled the page
    scroll_height = driver.execute_script("return document.body.scrollHeight;")  
    # Break the loop when the height we need to scroll to is larger than the total scroll height
    if (screen_height) * i > scroll_height:
        break
###

#Processing the HTML 
soup = BeautifulSoup(driver.page_source, "html.parser")
# print(soup.prettify()) basically prints out the page 
# find all divs with this class name 
videos = soup.find_all("div", {"class": "tiktok-yz6ijl-DivWrapper"}) 
#note that as we scroll down the page, then more things get loaded 
#print(len(videos))


### Now using ssstik.io (opening up the network tab->copying as curl(bash) and curlconverter(to convert to python)
def downloadVideo(link, id):
    cookies = {
        '__cflb': '02DiuEcwseaiqqyPC5qr2kcTPpjPMVimtoDCaGTnF4VHV',
    }

    headers = {
        'authority': 'ssstik.io',
        'accept': '*/*',
        'accept-language': 'en-US,en;q=0.9',
        'content-type': 'application/x-www-form-urlencoded; charset=UTF-8',
        # 'cookie': '__cflb=02DiuEcwseaiqqyPC5qr2kcTPpjPMVimtoDCaGTnF4VHV',
        'hx-current-url': 'https://ssstik.io/en',
        'hx-request': 'true',
        'hx-target': 'target',
        'hx-trigger': '_gcaptcha_pt',
        'origin': 'https://ssstik.io',
        'referer': 'https://ssstik.io/en',
        'sec-ch-ua': '"Not?A_Brand";v="8", "Chromium";v="108", "Google Chrome";v="108"',
        'sec-ch-ua-mobile': '?0',
        'sec-ch-ua-platform': '"Windows"',
        'sec-fetch-dest': 'empty',
        'sec-fetch-mode': 'cors',
        'sec-fetch-site': 'same-origin',
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36',
    }

    params = {
        'url': 'dl',
    }

    data = {
        'id': link,
        'locale': 'en',
        'tt': 'a3ZCWVRm',
    }
    # makes a request to post DATA into that link specifically 
    response = requests.post('https://ssstik.io/abc', params=params, cookies=cookies, headers=headers, data=data)
    #now using beautiful soup as before we parse the href that we got from there
    downloadSoup = BeautifulSoup(response.text, "html.parser")

    #now to get the <a> tag 
    downloadLink = downloadSoup.a["href"]
    
    #downloads the raw file here
    mp4File = urlopen(downloadLink)
    with open(f"videos/{id}.mp4", "wb") as output: # to write in binary 
        while True: # using a while loop to read the raw data and write the data into our output file 
            data = mp4File.read(4096) # max size of a file block 
            if data: # if we're able to read it
                output.write(data) 
            else: # basically end of file? then close it 
                break; 

for index, video in enumerate(videos): # .a grabs the <a> tag then grabs the href value
    downloadVideo(video.a["href"], index) # Calls downloadVideo for every 
    # There's a problem though, we can only download one video because we're making too many request at one time 
    time.sleep(10) 
    # print(video.a["href"]) prints the current video 
