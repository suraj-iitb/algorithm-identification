import mosspy

userid = 880539317

m = mosspy.Moss(userid, "cc")

# Submission Files
m.addFilesByWildcard("Data/BubbleSort/bubble*.cpp")
m.addFilesByWildcard("Data/InsertionSort/insertion*.cpp")

# Submission Report URL
url = m.send()
print ("Report Url: " + url)

# Save report file
m.saveWebPage(url, "Results/Bubble-InsertionSort/online-report.html")

# Download whole report locally including code diff links
mosspy.download_report(url, "Results/Bubble-InsertionSort/offline-report/", connections=8)