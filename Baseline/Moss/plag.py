import mosspy

############ Variables ###########
userid = 880539317
lang = "cc"

data1 = "Data/Bubble/Dump/bubble*.cpp"
data2 = "Data/Insertion/Dump/insertion*.cpp"

report = "Results/Raw/Dump/Bubble-Insertion/"
online_report = report + "online-report.html"
offline_report = report + "offline-report/"
#################################

m = mosspy.Moss(userid, lang)

# Submission Files
m.addFilesByWildcard(data1)
m.addFilesByWildcard(data2)

# Submission Report URL
url = m.send()
print ("Report Url: " + url)

# Save report file
m.saveWebPage(url, online_report)

# Download whole report locally including code diff links
mosspy.download_report(url, offline_report, connections=8)