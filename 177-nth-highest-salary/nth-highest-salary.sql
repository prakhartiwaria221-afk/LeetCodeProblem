CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
       SELECT MAX(E1.SALARY)
       FROM EMPLOYEE E1
       WHERE (
          SELECT COUNT(DISTINCT E2.SALARY)
          FROM EMPLOYEE E2
          WHERE E2.SALARY > E1.SALARY
       ) = N - 1
  );
END