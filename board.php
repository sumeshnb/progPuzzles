<?php
//----------------------------------------------------------------------------
//  Name: Sumesh Nellemakkal Balan
//  ID: 1001119408
//  URL: http://omega.uta.edu/~sxn9408/project4/board.php
//----------------------------------------------------------------------------
session_start();
?>

<html>
    <head>
        <title>Message Board</title>
        <style>
            body {
                background-color:  azure;
            }

            h1 {
                color: black;
                text-align: center;
            }

            p {
                font-family: "Times New Roman";
                font-size: 25px;
            }
            fieldset {
                overflow: hidden;
                float: left;
                position: absolute;
                left:40%;
                top:40%;
                right: 30%;
                
                margin:-100px 0 0 -150px;
                text-align:center;
                border: 1px #af3333 solid;
                border-radius: 8px;
            }
            table, td, th {
                border: 1px solid coral;
            }
            th {
                height: 30px;
            }
            td {
                padding: 15px;
            }
            table, td, th {
                border: 1px solid green;
            }
            td{
                background-color:   azure;
                font-family: monospace;
                font-size:  medium;
                font-style: italic;
            
            }

            th {
                background-color:   aliceblue;
                color: black;
            }
            table {
                border-collapse: collapse;
            }
            label{
                display:inline-block;
                width:200px;
                margin-right:30px;
                text-align:right;
            }
        </style>
    </head>
    <body>
        <?php
        makeDecision();

        function makeDecision() {
            if (!isset($_SESSION['loggedin'])) {
                $_SESSION['loggedin'] = 0;
            }
            error_reporting(E_ALL);
            ini_set('display_errors', 'On');
            if (isset($_GET['signup']) && isset($_GET['formfilled'])) {
                //echo 'form filled received :-)';
                registerUser();
            } else if (isset($_GET['newmessage'])) {
                showNewPostPage();
            } else if (isset($_GET['newmessagepost'])) {
                saveNewMessagePost();
            } else if (isset($_POST['username']) || isset($_POST['password'])) {
                //echo 'calling authentiateUser';
                authenticateUser();
                if ($_SESSION['loggedin'] == 1) {
                    //show Logged in page , ie page 2
                    showLoggedInPage();
                }
            } else if (isset($_GET['signup'])) {
                //echo 'signup page';
                showSignUpPage();
            } else if (isset($_GET['logout'])) {
                //logout
                session_destroy();
                showLogIn();
            } else if (1) {
                showLogIn();
            }
        }

        function authenticateUser() {
            try {
                $dbname = dirname($_SERVER["SCRIPT_FILENAME"]) . "/mydb.sqlite";
                $dbh = new PDO("sqlite:$dbname");

                $username = $_POST['username'];
                $password = $_POST['password'];

                $sql = 'select * from users where username="' . $username . '"';
                $result = $dbh->query($sql);
                $allRows = $result->fetchAll();
                foreach ($allRows as $row) {

                    if ($row['username'] == $username && $row['password'] == md5($password)) {
                        //user is authenticated
                        $_SESSION['loggedin'] = 1;
                        $_SESSION['user'] = $username;
                        //echo 'You are logged in';
                        break;
                    }
                }
                if ($_SESSION['loggedin'] == 0) {
                    showLogIn();
                }
            } catch (PDOException $e) {
                print "Error!: " . $e->getMessage() . "<br/>";
                die();
            }
        }

        function showLogIn() {
            echo <<<EOT
<form action="board.php" method="POST">
        <fieldset>
                <legend>Log In</legend>
        </br>
                     <label for="username">User Name:</label>
                        <input type="text"  name="username"><br />

                        <label for="password">Password:&nbsp;&nbsp;&nbsp;</label>
                        <input type="password" name="password"><br /><br>
        <input type="submit" value="Log In" /><br>
            <br>
        <a href="board.php?signup=true"><input type="button" name="signup" value="Register"></a>
        </fieldset>

</form>
        
EOT;
        }

        function showSignUpPage() {
            echo <<<EOT
            <form action="board.php?signup=true&formfilled=true" method="POST">
            <fieldset>
            <legend>Enter Details</legend>
            </br>
            <label for="username">User Name:</label>
            <input type="text"  name="username"><br />
            <label for="password">Password:</label>
            <input type="password" name="password"><br />
            <label for="fullname">Full Name:</label>
            <input type="text"  name="fullname"><br>
            <label for="username">Email:</label>
            <input type="email"  name="email"><br><br>
            <input type="submit" value="Register" /><br>
            </fieldset>

</form>
EOT;
        }

        function registerUser() {
            try {
                $dbname = dirname($_SERVER["SCRIPT_FILENAME"]) . "/mydb.sqlite";
                $dbh = new PDO("sqlite:$dbname");

                $username = $_POST['username'];
                $password = $_POST['password'];
                $fullname = $_POST['fullname'];
                $email = $_POST['email'];
                $sql = 'select * from users where username="' . $username . '"';
                $result = $dbh->query($sql);
                $allRows = $result->fetchAll();
                $unameexist = 0;
                foreach ($allRows as $row) {

                    if ($row['username'] == $username) {
                        //echo 'UserName already exists';
                        $unameexist = 1;
                        showSignUpPage();
                        break;
                    }
                }
                if ($unameexist == 0) {
                    //add userinfo to db 
                    $dbname = dirname($_SERVER["SCRIPT_FILENAME"]) . "/mydb.sqlite";
                    $dbh = new PDO("sqlite:$dbname");
                    $dbh->beginTransaction();

                    $query = 'insert into users values("' . $username . '","' . md5($password) . '","' . $fullname . '","' . $email . '")';
                    $dbh->exec($query)
                            or die(print_r($dbh->errorInfo(), true));
                    $dbh->commit();
                    showLogIn();
                }
            } catch (PDOException $e) {
                print "Error!: " . $e->getMessage() . "<br/>";
                die();
            }
        }

        function showLoggedInPage() {
            echo <<<EOT
            <div style="width:800px; margin:0 auto;">
                <div style="text-align:center">  
    <br>
            <br>

        <a href="board.php?logout=true"><input type="button" align="centre"
  width="48" height="48" name="logout" value="Logout"></a>
        <a href="board.php?newmessage=true"><input type="button" align="centre"
  width="48" height="48" name="newmessage" value="New Message"></a>
            <br><br>
            </div> 
       </div>
EOT;
            showPosts();
        }

        function showNewPostPage() {
            if ($_SESSION['loggedin'] == 1) {

                if (isset($_GET['follows'])) {
                    $_SESSION['follows'] = $_GET['follows'];
                }
                echo <<<EOT
            
            <form action="board.php?newmessagepost=true" method="POST">
            
            </br>
                
                <br>
                <fieldset  >
                <legend>Enter your message here</legend>
                <br>
           <textarea rows="10" cols="70" name="post"align="center"></textarea>
                <br><br>
            <input type="submit" value="Post" /><br>
                </fieldset>
            
</form>
       
EOT;
                //showPosts();
            } else {
                showLogIn();
            }
        }

        function saveNewMessagePost() {
            if ($_SESSION['loggedin'] == 1) {

                try {
                    $dbname = dirname($_SERVER["SCRIPT_FILENAME"]) . "/mydb.sqlite";
                    $dbh = new PDO("sqlite:$dbname");

                    $text = $_POST['post'];
                    $follows;
                    if (isset($_SESSION['follows'])) {
                        //this post is following some other post
                        $follows = $_SESSION['follows'];
                        unset($_SESSION['follows']);
                    } else {
                        $follows = "None";
                    }
                    $id = uniqid();
                    $user = $_SESSION['user'];

                    $sql = 'select strftime(\'%s\',\'now\')';
                    $result = $dbh->query($sql);
                    $allRows = $result->fetchAll();
                    //$unameexist = 0;
                    $datetime = 0;
                    foreach ($allRows as $row) {
                        $datetime = $row[0];
                    }

                    //add userinfo to db 
                    $dbname = dirname($_SERVER["SCRIPT_FILENAME"]) . "/mydb.sqlite";
                    $dbh = new PDO("sqlite:$dbname");
                    $dbh->beginTransaction();

                    $query = 'insert into posts values("' . $id . '","' . $user . '","' . $follows . '",' . $datetime . ',"' . $text . '")';
                    //echo $query;

                    $dbh->exec($query)
                            or die(print_r($dbh->errorInfo(), true));
                    $dbh->commit();
                    //showNewPostPage();
                } catch (PDOException $e) {
                    print "Error!: " . $e->getMessage() . "<br/>";
                    die();
                }
                showLoggedInPage();
            } else {
                showLogIn();
            }
        }

        function showPosts() {
            try {
                $dbname = dirname($_SERVER["SCRIPT_FILENAME"]) . "/mydb.sqlite";
                $dbh = new PDO("sqlite:$dbname");

                $sql = 'select * from posts order by datetime asc';
                $result = $dbh->query($sql);
                $allRows = $result->fetchAll();
                //$unameexist = 0;
                $datetime = 0;
                echo'<div style="text-align:center">';
                echo '<h3>Message Board</h3>';
                echo '</div>';
                echo ' <div style="width:900px; margin:0 auto;">';
                echo '<table>';
                foreach ($allRows as $row) {
                    $id = $row['id'];
                    $postedby = $row['postedby'];
                    $follows = $row['follows'];
                    $datetime = $row['datetime'];
                    $message = $row['message'];
                    $fullname = "null";

                    //we have to findout full name of user
                    $sql1 = 'select fullname from users where username="' . $postedby . '"';
                    //echo '<br>'.$sql1.'<br>';
                    $result1 = $dbh->query($sql1);
                    $allRows1 = $result1->fetchAll();
                    foreach ($allRows1 as $row1) {
                        $fullname = $row1[0];
                        //echo $fullname;
                    }

                    $sql2 = 'select datetime(' . $datetime . ',\'unixepoch\',\'localtime\')';
                    $result2 = $dbh->query($sql2);
                    $allRows2 = $result2->fetchAll();
                    //$unameexist = 0;
                    $localtime = "localtime";
                    foreach ($allRows2 as $row2) {
                        $localtime = $row2[0];
                    }

                    echo '<th> User Name: ' . $postedby . '&nbsp; Full Name: ' . $fullname .
                    '&nbsp;Id: ' . $id . '&nbsp;Time Created: ' . $localtime . '&nbsp;Follows: ' . $follows . '</th>';
                    echo '<tr><td>' . $message .
                    '</td><td><a href="board.php?newmessage=true&follows=' . $id . '"><input type="button" name="reply" value="reply"></a></tr></td>';
                }
                echo'</table>';
                echo '</div>';
            } catch (PDOException $e) {
                print "Error!: " . $e->getMessage() . "<br/>";
                die();
            }
        }
        ?>
    </body>
</html>