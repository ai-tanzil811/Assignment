# Exam Basics — Testing and Logging Templates

Use these minimal, copy-ready templates during exams.

## Pytest Starter

```python
# tests/test_example.py
def test_math():
    assert 1 + 1 == 2
```

## Arrange–Act–Assert

```python
def add(a, b):
    return a + b

def test_add():
    # Arrange
    a, b = 2, 3
    # Act
    result = add(a, b)
    # Assert
    assert result == 5
```

## Logging Basics + caplog

```python
import logging

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s [%(levelname)s] %(name)s: %(message)s'
)
logger = logging.getLogger('demo')

def greet(name: str) -> str:
    logger.info('Greeting %s', name)
    return f'Hello, {name}!'

def test_greet_logs(caplog):
    caplog.set_level(logging.INFO, logger='demo')
    assert greet('Ada') == 'Hello, Ada!'
    assert any('Greeting Ada' in r.getMessage() for r in caplog.records)
```

## Selenium Smoke (Explicit Waits)

```python
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

def test_saucedemo_login_smoke():
    driver = webdriver.Chrome()
    try:
        driver.get('https://www.saucedemo.com/')
        wait = WebDriverWait(driver, 10)
        wait.until(EC.visibility_of_element_located((By.ID, 'user-name'))).send_keys('standard_user')
        wait.until(EC.visibility_of_element_located((By.ID, 'password'))).send_keys('secret_sauce')
        wait.until(EC.element_to_be_clickable((By.ID, 'login-button'))).click()
        wait.until(EC.url_contains('inventory.html'))
        assert 'inventory' in driver.current_url
    finally:
        driver.quit()
```

## Quick Commands

- Run all tests: `pytest -v`
- Run one file: `pytest -v tests/test_login.py`
- Show live logs: `pytest -v --log-cli-level=INFO`
