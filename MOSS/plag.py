import mosspy
import os

############ Variables ###########
userid = 880539317
lang = "cc"

limit = 100

report = "Results/Raw/Dump/All/"+str(limit)+"/"
online_report = report + "online-report.html"
# offline_report = report + "offline-report/"
#################################

m = mosspy.Moss(userid, lang)

# Submission Files
for algo in os.listdir('Data'):
    if not algo.endswith('.txt'):
        count = 1
        for code in os.listdir('Data/' + algo + '/Dump/C'):
            if not code.endswith('.txt'):
                if count <= limit:
                    print(code)
                    m.addFile('Data/' + algo + '/Dump/C/' + code)
                    count += 1

# Submission Report URL
url = m.send()
print ("Report Url: " + url)

# Save report file
m.saveWebPage(url, online_report)

# Download whole report locally including code diff links
# mosspy.download_report(url, offline_report, connections=8)