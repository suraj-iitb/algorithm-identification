import mosspy

userid = 880539317

m = mosspy.Moss(userid, "cc")

# Submission Files
m.addFilesByWildcard("Data/BubbleSort/Dump/bubble*.cpp")
m.addFilesByWildcard("Data/InsertionSort/Dump/insetion*.cpp")

# Submission Report URL
url = m.send()
print ("Report Url: " + url)

# Save report file
m.saveWebPage(url, "Results/Bubble-InsertionSort/Dump/online-report.html")

# Download whole report locally including code diff links
mosspy.download_report(url, "Results/Bubble-InsertionSort/Dump/offline-report/", connections=8)