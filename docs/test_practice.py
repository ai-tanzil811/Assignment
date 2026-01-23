from datetime import datetime
from selenium import webdriver
import time
from selenium.webdriver.common.by import By

LOG_fILE = "tanzil.log"


def log(message, level="INFO"):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    log_entry = f"[{timestamp}][{level}][{message}]\n"

    with open(LOG_fILE, "a") as file:
        file.write(log_entry)


def test_practice():
    driver = webdriver.Chrome()
    try:
        driver.maximize_window()
        
        driver.get("https://elms.uiu.ac.bd/")

        driver.find_element(By.CLASS_NAME, "usermenu").click()
        assert "https://elms.uiu.ac.bd/login/index.php" in driver.current_url
        time.sleep(1)
        driver.find_element(By.ID, "username").send_keys("0112230028")
        time.sleep(1)
        driver.find_element(By.ID, "password").send_keys("#Asdfgh31")
        time.sleep(1)
        driver.find_element(By.ID, "loginbtn").click()
        time.sleep(2)
        assert "https://elms.uiu.ac.bd/my/" in driver.current_url
        error_elements = driver.find_elements(By.ID, "loginerrormessage")
        print(error_elements)

        if len(error_elements) != 0:
            log("wrong cred")
        else:
            log(" all ok")
        time.sleep(2)
    finally:
        driver.quit()

def test_fail_practice():
    time.sleep(1)
    driver = webdriver.Chrome()
    try:
        driver.maximize_window()
        
        driver.get("https://elms.uiu.ac.bd/")

        driver.find_element(By.CLASS_NAME, "usermenu").click()
        assert "https://elms.uiu.ac.bd/login/index.php" in driver.current_url
        time.sleep(1)
        driver.find_element(By.ID, "username").send_keys("0112230028")
        time.sleep(1)
        driver.find_element(By.ID, "password").send_keys("wrongpassword")
        time.sleep(1)
        driver.find_element(By.ID, "loginbtn").click()
        time.sleep(2)
        
        error_elements = driver.find_elements(By.ID, "loginerrormessage").text
        assert "Invalid login, please try again" in error_elements
        print(error_elements)

        if len(error_elements) != 0:
            log("wrong cred")
        else:
            log(" all ok")
        time.sleep(2)
    finally:
        driver.quit()