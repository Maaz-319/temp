<?php

/*
===========================================================
 PHP BASICS - SINGLE FILE FOR CLASSROOM TEACHING
===========================================================

File:
    /var/www/dev/public/php_basics.php

URL:
    http://dev.local/php_basics.php

TEACHING METHOD:
    Uncomment ONE section at a time.
    Run the file in the browser.
    Explain the output.
    Then move to the next task.

IMPORTANT:
    PHP code must be inside:

        <?php
        ?>

===========================================================
*/


/*
===========================================================
TASK 01 - HELLO WORLD
===========================================================
Concepts:
    - PHP opening tag
    - echo
    - HTML + PHP
===========================================================
*/

// echo "Hello World!";
// echo "<h1>Hello PHP Students!</h1>";



/*
===========================================================
TASK 02 - PHP COMMENTS
===========================================================
Concepts:
    - Single-line comments
    - Multi-line comments
===========================================================
*/

// This is a single-line comment

/*
   This is
   a multi-line
   comment
*/

// echo "Comments are not displayed in the browser.";



/*
===========================================================
TASK 03 - PRINT TEXT
===========================================================
Concepts:
    - echo
    - print
    - HTML inside PHP
===========================================================
*/

// echo "This is echo.";
// print "This is print.";

// echo "<h2>PHP Programming</h2>";
// echo "<p>PHP runs on the server.</p>";



/*
===========================================================
TASK 04 - VARIABLES
===========================================================
Concepts:
    - Variables
    - $ symbol
    - Strings
    - Integers
===========================================================
*/

// $name = "Ali";
// $age = 20;

// echo $name;
// echo "<br>";
// echo $age;



/*
===========================================================
TASK 05 - VARIABLE OUTPUT
===========================================================
Concepts:
    - Combining variables with text
===========================================================
*/

// $name = "Ali";
// $age = 20;

// echo "My name is $name";
// echo "<br>";
// echo "I am $age years old.";



/*
===========================================================
TASK 06 - VARIABLE CONCATENATION
===========================================================
Concepts:
    - Dot operator
    - String concatenation
===========================================================
*/

// $firstName = "Ali";
// $lastName = "Khan";

// $fullName = $firstName . " " . $lastName;

// echo $fullName;



/*
===========================================================
TASK 07 - DATA TYPES
===========================================================
Concepts:
    - String
    - Integer
    - Float
    - Boolean
    - NULL
===========================================================
*/

$name = "Ali";
// $age = 20;
// $height = 5.9;
// $isStudent = true;
// $address = null;

// var_dump($name);
// echo "<br>";

// var_dump($age);
// echo "<br>";

// var_dump($height);
// echo "<br>";

// var_dump($isStudent);
// echo "<br>";

// var_dump($address);



/*
===========================================================
TASK 08 - ARITHMETIC OPERATORS
===========================================================
Concepts:
    + addition
    - subtraction
    * multiplication
    / division
    % modulus
    ** exponent
===========================================================
*/

// $a = 10;
// $b = 3;

// echo $a + $b;
// echo "<br>";

// echo $a - $b;
// echo "<br>";

// echo $a * $b;
// echo "<br>";

// echo $a / $b;
// echo "<br>";

// echo $a % $b;
// echo "<br>";

// echo $a ** $b;



/*
===========================================================
TASK 09 - ASSIGNMENT OPERATORS
===========================================================
===========================================================
*/

// $number = 10;

// $number += 5;

// echo $number;

// $number -= 2;

// echo "<br>";
// echo $number;

// $number *= 3;

// echo "<br>";
// echo $number;



/*
===========================================================
TASK 10 - COMPARISON OPERATORS
===========================================================
Concepts:
    ==
    ===
    !=
    !==
    >
    <
    >=
    <=
===========================================================
*/

// $a = 10;
// $b = "10";

// var_dump($a == $b);
// echo "<br>";

// var_dump($a === $b);
// echo "<br>";

// var_dump($a != $b);
// echo "<br>";

// var_dump($a !== $b);



/*
===========================================================
TASK 11 - IF STATEMENT
===========================================================
===========================================================
*/

// $age = 20;

// if ($age >= 18) {
//     echo "You are an adult.";
// }



/*
===========================================================
TASK 12 - IF ELSE
===========================================================
===========================================================
*/

// $age = 16;

// if ($age >= 18) {

//     echo "You can vote.";

// } else {

//     echo "You cannot vote.";

// }



/*
===========================================================
TASK 13 - IF / ELSEIF / ELSE
===========================================================
===========================================================
*/

// $marks = 75;

// if ($marks >= 80) {

//     echo "Grade A";

// } elseif ($marks >= 70) {

//     echo "Grade B";

// } elseif ($marks >= 60) {

//     echo "Grade C";

// } elseif ($marks >= 50) {

//     echo "Grade D";

// } else {

//     echo "Fail";

// }



/*
===========================================================
TASK 14 - LOGICAL OPERATORS
===========================================================
Concepts:
    &&
    ||
    !
===========================================================
*/

// $age = 25;
// $hasCNIC = true;

// if ($age >= 18 && $hasCNIC == true) {

//     echo "You can register.";

// }



/*
===========================================================
TASK 15 - SWITCH
===========================================================
===========================================================
*/

// $day = 3;

// switch ($day) {

//     case 1:
//         echo "Monday";
//         break;

//     case 2:
//         echo "Tuesday";
//         break;

//     case 3:
//         echo "Wednesday";
//         break;

//     case 4:
//         echo "Thursday";
//         break;

//     case 5:
//         echo "Friday";
//         break;

//     default:
//         echo "Invalid day";

// }



/*
===========================================================
TASK 16 - TERNARY OPERATOR
===========================================================
===========================================================
*/

// $age = 20;

// $result = ($age >= 18) ? "Adult" : "Minor";

// echo $result;



/*
===========================================================
TASK 17 - NULL COALESCING OPERATOR

The nullish coalescing operator (??) is a logical operator in JavaScript that returns 
its right-hand operand when its left-hand operand is null or undefined. Otherwise, it 
returns its left-hand operand.
===========================================================
===========================================================
*/

// $username = null;

// $name = $username ?? "Guest";

// echo $name;



/*
===========================================================
TASK 18 - WHILE LOOP
===========================================================
===========================================================
*/

// $i = 1;

// while ($i <= 5) {

//     echo $i;
//     echo "<br>";

//     $i++;

// }



/*
===========================================================
TASK 19 - DO WHILE LOOP
===========================================================
===========================================================
*/

// $i = 1;

// do {

//     echo $i;
//     echo "<br>";

//     $i++;

// } while ($i <= 5);



/*
===========================================================
TASK 20 - FOR LOOP
===========================================================
===========================================================
*/

// for ($i = 1; $i <= 10; $i++) {

//     echo $i;
//     echo "<br>";

// }



/*
===========================================================
TASK 21 - PRINT TABLE
===========================================================
===========================================================
*/

// $number = 5;

// for ($i = 1; $i <= 10; $i++) {

//     echo "$number x $i = " . ($number * $i);
//     echo "<br>";

// }



/*
===========================================================
TASK 22 - BREAK
===========================================================
===========================================================
*/

// for ($i = 1; $i <= 10; $i++) {

//     if ($i == 6) {
//         break;
//     }

//     echo $i . "<br>";

// }



/*
===========================================================
TASK 23 - CONTINUE
===========================================================
===========================================================
*/

// for ($i = 1; $i <= 10; $i++) {

//     if ($i == 5) {
//         continue;
//     }

//     echo $i . "<br>";

// }



/*
===========================================================
TASK 24 - INDEXED ARRAY
===========================================================
===========================================================
*/

// $students = ["Ali", "Ahmed", "Sara", "Ayesha"];

// echo $students[0];
// echo "<br>";

// echo $students[2];



/*
===========================================================
TASK 25 - COUNT ARRAY
===========================================================
===========================================================
*/

// $students = ["Ali", "Ahmed", "Sara", "Ayesha"];

// echo "Total Students: " . count($students);



/*
===========================================================
TASK 26 - FOREACH ARRAY
===========================================================
===========================================================
*/

// $students = ["Ali", "Ahmed", "Sara", "Ayesha"];

// foreach ($students as $student) {

//     echo $student;
//     echo "<br>";

// }



/*
===========================================================
TASK 27 - ASSOCIATIVE ARRAY
===========================================================
===========================================================
*/

// $student = [
//     "name" => "Ali",
//     "age" => 21,
//     "department" => "Computer Science"
// ];

// echo $student["name"];
// echo "<br>";

// echo $student["age"];
// echo "<br>";

// echo $student["department"];



/*
===========================================================
TASK 28 - FOREACH ASSOCIATIVE ARRAY
===========================================================
===========================================================
*/

// $student = [
//     "name" => "Ali",
//     "age" => 21,
//     "department" => "Computer Science"
// ];

// foreach ($student as $key => $value) {

//     echo "$key : $value";
//     echo "<br>";

// }



/*
===========================================================
TASK 29 - MULTIDIMENSIONAL ARRAY
===========================================================
===========================================================
*/

// $students = [

//     [
//         "name" => "Ali",
//         "age" => 20
//     ],

//     [
//         "name" => "Ahmed",
//         "age" => 21
//     ],

//     [
//         "name" => "Sara",
//         "age" => 22
//     ]

// ];

// echo $students[0]["name"];
// echo "<br>";

// echo $students[1]["age"];



/*
===========================================================
TASK 30 - FUNCTIONS
===========================================================
===========================================================
*/

// function sayHello() {

//     echo "Hello Students!";

// }

// sayHello();



/*
===========================================================
TASK 31 - FUNCTION PARAMETERS
===========================================================
===========================================================
*/

// function greet($name) {

//     echo "Hello " . $name;

// }

// greet("Ali");

// echo "<br>";

// greet("Ahmed");



/*
===========================================================
TASK 32 - FUNCTION RETURN VALUE
===========================================================
===========================================================
*/

// function add($a, $b) {

//     return $a + $b;

// }

// $result = add(10, 20);

// echo $result;



/*
===========================================================
TASK 33 - FUNCTION WITH TYPE DECLARATIONS
===========================================================
===========================================================
*/

// function addNumbers(int $a, int $b): int {

//     return $a + $b;

// }

// echo addNumbers(10, 20);



/*
===========================================================
TASK 34 - STRING FUNCTIONS
===========================================================
===========================================================
*/

// $text = "Hello PHP Students";

// echo strlen($text);
// echo "<br>";

// echo strtoupper($text);
// echo "<br>";

// echo strtolower($text);
// echo "<br>";

// echo str_replace("PHP", "Web", $text);



/*
===========================================================
TASK 35 - STRING POSITION
===========================================================
===========================================================
*/

// $text = "Hello PHP Students";

// echo strpos($text, "PHP");



/*
===========================================================
TASK 36 - NUMBER FUNCTIONS
===========================================================
===========================================================
*/

// $number = -25.75;

// echo abs($number);
// echo "<br>";

// echo round($number);
// echo "<br>";

// echo ceil($number);
// echo "<br>";

// echo floor($number);



/*
===========================================================
TASK 37 - RANDOM NUMBER
===========================================================
===========================================================
*/

// echo rand(1, 100);



/*
===========================================================
TASK 38 - DATE AND TIME
===========================================================
===========================================================
*/

// echo date("Y-m-d");
// echo "<br>";

// echo date("H:i:s");
// echo "<br>";

// echo date("l");



/*
===========================================================
TASK 39 - INCLUDE
===========================================================
Concept:
    Reuse another PHP file.
===========================================================
*/

// include "header.php";

// echo "Main page content";

// include "footer.php";



/*
===========================================================
TASK 40 - REQUIRE
===========================================================
===========================================================
*/

// require "config.php";

// echo "Configuration loaded.";



/*
===========================================================
TASK 41 - HTML FORM - GET
===========================================================
Concepts:
    - HTML form
    - GET
    - $_GET
===========================================================
*/

// ?>

<!--
<form method="GET">

    <label>Enter your name:</label>

    <input type="text" name="name">

    <button type="submit">Submit</button>

</form>
-->

<?php

// if (isset($_GET["name"])) {

//     $name = $_GET["name"];

//     echo "Hello " . htmlspecialchars($name);

// }



/*
===========================================================
TASK 42 - HTML FORM - POST
===========================================================
Concepts:
    - POST
    - $_POST
===========================================================
*/

// ?>

<!--
<form method="POST">

    <label>Name:</label>

    <input type="text" name="name">

    <br><br>

    <label>Email:</label>

    <input type="email" name="email">

    <br><br>

    <button type="submit">Submit</button>

</form>
-->

<?php

// if ($_SERVER["REQUEST_METHOD"] == "POST") {

//     $name = $_POST["name"];
//     $email = $_POST["email"];

//     echo "Name: " . htmlspecialchars($name);
//     echo "<br>";
//     echo "Email: " . htmlspecialchars($email);

// }



/*
===========================================================
TASK 43 - FORM VALIDATION
===========================================================
===========================================================
*/

// ?>

<!--
<form method="POST">

    <input
        type="text"
        name="name"
        placeholder="Enter name"
    >

    <button type="submit">
        Submit
    </button>

</form>
-->

<?php

// if ($_SERVER["REQUEST_METHOD"] == "POST") {

//     if (empty($_POST["name"])) {

//         echo "Name is required.";

//     } else {

//         $name = htmlspecialchars($_POST["name"]);

//         echo "Welcome " . $name;

//     }

// }



/*
===========================================================
TASK 44 - EMAIL VALIDATION
===========================================================
===========================================================
*/

// ?>

<!--
<form method="POST">

    <input
        type="email"
        name="email"
        placeholder="Enter email"
    >

    <button type="submit">
        Validate
    </button>

</form>
-->

<?php

// if ($_SERVER["REQUEST_METHOD"] == "POST") {

//     $email = $_POST["email"];

//     if (filter_var($email, FILTER_VALIDATE_EMAIL)) {

//         echo "Valid email.";

//     } else {

//         echo "Invalid email.";

//     }

// }



/*
===========================================================
TASK 45 - SUPERGLOBALS
===========================================================
Concepts:
    $_GET
    $_POST
    $_SERVER
    $_SESSION
    $_COOKIE
    $_FILES
===========================================================
*/

// echo "<pre>";

// print_r($_SERVER);

// echo "</pre>";



/*
===========================================================
TASK 46 - SESSION
===========================================================
===========================================================
*/

// session_start();

// $_SESSION["username"] = "Ali";

// echo "Session created.";



/*
===========================================================
TASK 47 - READ SESSION
===========================================================
===========================================================
*/

// session_start();

// if (isset($_SESSION["username"])) {

//     echo "Welcome " . $_SESSION["username"];

// } else {

//     echo "No session found.";

// }



/*
===========================================================
TASK 48 - DESTROY SESSION
===========================================================
===========================================================
*/

// session_start();

// session_unset();

// session_destroy();

// echo "Session destroyed.";



/*
===========================================================
TASK 49 - COOKIE
===========================================================
===========================================================
*/

// setcookie("student", "Ali", time() + 3600);

// echo "Cookie created.";



/*
===========================================================
TASK 50 - READ COOKIE
===========================================================
===========================================================
*/

// if (isset($_COOKIE["student"])) {

//     echo "Student: " . $_COOKIE["student"];

// } else {

//     echo "Cookie not found.";

// }



/*
===========================================================
TASK 51 - FILE WRITE
===========================================================
Concepts:
    - file_put_contents()
===========================================================
*/

// $message = "Hello PHP Students\n";

// file_put_contents("students.txt", $message);

// echo "Data written to file.";



/*
===========================================================
TASK 52 - FILE READ
===========================================================
===========================================================
*/

// $data = file_get_contents("students.txt");

// echo nl2br($data);



/*
===========================================================
TASK 53 - CHECK FILE
===========================================================
===========================================================
*/

// if (file_exists("students.txt")) {

//     echo "File exists.";

// } else {

//     echo "File does not exist.";

// }



/*
===========================================================
TASK 54 - BASIC ERROR HANDLING
===========================================================
===========================================================
*/

// $number = 10;

// if ($number == 0) {

//     echo "Cannot divide by zero.";

// } else {

//     echo 100 / $number;

// }



/*
===========================================================
TASK 55 - TRY / CATCH
===========================================================
===========================================================
*/

// try {

//     throw new Exception("Something went wrong.");

// } catch (Exception $e) {

//     echo "Error: " . $e->getMessage();

// }



/*
===========================================================
TASK 56 - MYSQL DATABASE CONNECTION
===========================================================
Concepts:
    - mysqli
    - Database connection
===========================================================

Your configured database:

Database: devdb
User:     devuser
Password: DevPassword123!
Host:     localhost
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// if ($conn->connect_error) {

//     die("Database connection failed: " . $conn->connect_error);

// }

// echo "Database connected successfully.";

// $conn->close();



/*
===========================================================
TASK 57 - CREATE DATABASE TABLE
===========================================================
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// if ($conn->connect_error) {

//     die("Connection failed: " . $conn->connect_error);

// }

// $sql = "
// CREATE TABLE IF NOT EXISTS students (

//     id INT AUTO_INCREMENT PRIMARY KEY,
//     name VARCHAR(100) NOT NULL,
//     email VARCHAR(150) NOT NULL,
//     age INT,
//     created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP

// )
// ";

// if ($conn->query($sql) === TRUE) {

//     echo "Students table created.";

// } else {

//     echo "Error: " . $conn->error;

// }

// $conn->close();



/*
===========================================================
TASK 58 - INSERT DATA
===========================================================
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// $name = "Ali";
// $email = "ali@example.com";
// $age = 21;

// $sql = "
// INSERT INTO students (name, email, age)
// VALUES ('$name', '$email', $age)
// ";

// if ($conn->query($sql) === TRUE) {

//     echo "Student inserted.";

// } else {

//     echo "Error: " . $conn->error;

// }

// $conn->close();



/*
===========================================================
TASK 59 - SELECT DATA
===========================================================
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// $sql = "SELECT id, name, email, age FROM students";

// $result = $conn->query($sql);

// if ($result->num_rows > 0) {

//     while ($row = $result->fetch_assoc()) {

//         echo "ID: " . $row["id"];
//         echo "<br>";

//         echo "Name: " . htmlspecialchars($row["name"]);
//         echo "<br>";

//         echo "Email: " . htmlspecialchars($row["email"]);
//         echo "<br>";

//         echo "Age: " . $row["age"];
//         echo "<hr>";

//     }

// } else {

//     echo "No students found.";

// }

// $conn->close();



/*
===========================================================
TASK 60 - SELECT DATA INTO HTML TABLE
===========================================================
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// $result = $conn->query(
//     "SELECT * FROM students"
// );

// ?>

<!--
<table border="1" cellpadding="8">

    <tr>

        <th>ID</th>
        <th>Name</th>
        <th>Email</th>
        <th>Age</th>

    </tr>

<?php

// while ($row = $result->fetch_assoc()) {

// ?>

    <tr>

        <td><?= $row["id"] ?></td>

        <td>
            <?= htmlspecialchars($row["name"]) ?>
        </td>

        <td>
            <?= htmlspecialchars($row["email"]) ?>
        </td>

        <td>
            <?= $row["age"] ?>
        </td>

    </tr>

<?php

// }

// ?>

</table>
-->

<?php

// $conn->close();



/*
===========================================================
TASK 61 - UPDATE DATA
===========================================================
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// $sql = "
// UPDATE students
// SET age = 25
// WHERE id = 1
// ";

// if ($conn->query($sql) === TRUE) {

//     echo "Student updated.";

// } else {

//     echo "Error: " . $conn->error;

// }

// $conn->close();



/*
===========================================================
TASK 62 - DELETE DATA
===========================================================
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// $sql = "
// DELETE FROM students
// WHERE id = 1
// ";

// if ($conn->query($sql) === TRUE) {

//     echo "Student deleted.";

// } else {

//     echo "Error: " . $conn->error;

// }

// $conn->close();



/*
===========================================================
TASK 63 - PREPARED STATEMENT
===========================================================
IMPORTANT:
    Introduce this after students understand INSERT.

    Prepared statements should be used instead of directly
    putting user input into SQL queries.
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// $name = "Ahmed";
// $email = "ahmed@example.com";
// $age = 22;

// $stmt = $conn->prepare(
//     "INSERT INTO students (name, email, age)
//      VALUES (?, ?, ?)"
// );

// $stmt->bind_param(
//     "ssi",
//     $name,
//     $email,
//     $age
// );

// $stmt->execute();

// echo "Student inserted using prepared statement.";

// $stmt->close();
// $conn->close();



/*
===========================================================
TASK 64 - PREPARED SELECT
===========================================================
===========================================================
*/

// $conn = new mysqli(
//     "localhost",
//     "devuser",
//     "DevPassword123!",
//     "devdb"
// );

// $id = 1;

// $stmt = $conn->prepare(
//     "SELECT id, name, email, age
//      FROM students
//      WHERE id = ?"
// );

// $stmt->bind_param("i", $id);

// $stmt->execute();

// $result = $stmt->get_result();

// while ($row = $result->fetch_assoc()) {

//     echo "Name: " . htmlspecialchars($row["name"]);
//     echo "<br>";

//     echo "Email: " . htmlspecialchars($row["email"]);
//     echo "<br>";

//     echo "Age: " . $row["age"];

// }

// $stmt->close();
// $conn->close();



/*
===========================================================
TASK 65 - COMPLETE MINI PROJECT
===========================================================

Student Registration System

Concepts combined:

    HTML
    PHP
    POST
    Validation
    MySQL
    INSERT
    Prepared Statements
    SELECT
    HTML table
    htmlspecialchars()

===========================================================
*/

// ?>

<!--

<h2>Student Registration</h2>

<form method="POST">

    <label>Name:</label>

    <input
        type="text"
        name="name"
        required
    >

    <br><br>

    <label>Email:</label>

    <input
        type="email"
        name="email"
        required
    >

    <br><br>

    <label>Age:</label>

    <input
        type="number"
        name="age"
        required
    >

    <br><br>

    <button type="submit" name="save">
        Save Student
    </button>

</form>

<hr>

-->

<?php

/*
if (isset($_POST["save"])) {

    $name = trim($_POST["name"]);
    $email = trim($_POST["email"]);
    $age = (int) $_POST["age"];

    if (empty($name)) {

        echo "Name is required.";

    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {

        echo "Invalid email.";

    } elseif ($age < 1 || $age > 120) {

        echo "Invalid age.";

    } else {

        $conn = new mysqli(
            "localhost",
            "devuser",
            "DevPassword123!",
            "devdb"
        );

        if ($conn->connect_error) {

            die(
                "Database connection failed: "
                . $conn->connect_error
            );

        }

        $stmt = $conn->prepare(
            "INSERT INTO students (name, email, age)
             VALUES (?, ?, ?)"
        );

        $stmt->bind_param(
            "ssi",
            $name,
            $email,
            $age
        );

        if ($stmt->execute()) {

            echo "Student registered successfully.";

        } else {

            echo "Error: " . $stmt->error;

        }

        $stmt->close();
        $conn->close();

    }

}
*/


/*
===========================================================
END OF PHP BASICS
===========================================================

Suggested teaching progression:

1.  Hello World
2.  Comments
3.  echo / print
4.  Variables
5.  Variable output
6.  Concatenation
7.  Data types
8.  Arithmetic operators
9.  Assignment operators
10. Comparison operators
11. if
12. if / else
13. elseif
14. Logical operators
15. switch
16. Ternary
17. Null coalescing
18. while
19. do while
20. for
21. Multiplication table
22. break
23. continue
24. Indexed arrays
25. count()
26. foreach
27. Associative arrays
28. Associative foreach
29. Multidimensional arrays
30. Functions
31. Parameters
32. Return values
33. Type declarations
34. String functions
35. String searching
36. Number functions
37. Random numbers
38. Date/time
39. include
40. require
41. GET form
42. POST form
43. Validation
44. Email validation
45. Superglobals
46. Sessions
47. Reading sessions
48. Destroying sessions
49. Cookies
50. Reading cookies
51. Writing files
52. Reading files
53. File checking
54. Basic error handling
55. Exceptions
56. MySQL connection
57. Create table
58. INSERT
59. SELECT
60. SELECT + HTML table
61. UPDATE
62. DELETE
63. Prepared INSERT
64. Prepared SELECT
65. Complete mini project

===========================================================
*/
?>