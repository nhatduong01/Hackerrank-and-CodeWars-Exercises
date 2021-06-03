def format_duration(seconds):
    if seconds == 0:
        return "now"
    if seconds < 60:
        if seconds == 1:
            return "1 second"
        else:
            return str(seconds) + " seconds"
    constant = [31536000, 86400, 3600, 60]
    final_str = ""
    if seconds >= constant[0]:
        num = 0
        while seconds >= constant[0]:
            num += 1
            seconds -= constant[0]
        if num == 1:
            final_str += "1 year"
        else:
            final_str += str(num) + " years"
    if seconds == 0:
        return final_str
    if final_str != "" and seconds % constant[1] == 0:
        final_str += " and "
    if seconds >= constant[1]:
        if final_str != "" and final_str[-1] != " ":
            final_str += ", "
        num = 0
        while seconds >= constant[1]:
            num += 1
            seconds -= constant[1]
        if num == 1:
            final_str += "1 day"
        else:
            final_str += str(num) + " days"
    if seconds == 0:
        return final_str
    if final_str != "" and seconds % constant[2] == 0:
        final_str += " and "
    if seconds >= constant[2]:
        if final_str != "" and final_str[-1] != " ":
            final_str += ", "
        num = 0
        while seconds >= constant[2]:
            num += 1
            seconds -= constant[2]
        if num == 1:
            final_str += "1 hour"
        else:
            final_str += str(num) + " hours"
    if seconds == 0:
        return final_str
    if final_str != "" and seconds % constant[3] == 0:
        final_str += " and "
    if seconds >= constant[3]:
        if final_str != "" and final_str[-1] != " ":
            final_str += ", "
        num = 0
        while seconds >= constant[3]:
            num += 1
            seconds -= constant[3]
        if num == 1:
            final_str += "1 minute"
        else:
            final_str += str(num) + " minutes"
    if seconds == 0:
        return final_str
    if seconds == 1:
        final_str += " and 1 second"
    else:
        final_str += " and " + str(seconds) + " seconds"
    return final_str


#print(format_duration(2*31536000 + 256*86400+0*3600 + 5*60 + 0*1))
print(format_duration(180))
