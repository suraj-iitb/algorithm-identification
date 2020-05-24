import mosspy

userid = 880539317

m = mosspy.Moss(userid, "cc")

# Submission Files
m.addFilesByWildcard("Data/BubbleSort/bubble*.cpp")

# Submission Report URL
url = m.send()
print ("Report Url: " + url)

# Save report file
m.saveWebPage(url, "Results/BubbleSort/online-report.html")

# Download whole report locally including code diff links
mosspy.download_report(url, "Results/BubbleSort/offline-report/", connections=8)