SELECT* FROM USERS
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode[.]com$'
AND HEX(SUBSTRING_INDEX(mail, '@', -1)) = HEX('leetcode.com');