# Exam Advanced — Testing and Logging Templates

These patterns cover parametrization, fixtures, markers, POM, and production logging.

## Parametrize, Skip, XFail

```python
import pytest

@pytest.mark.parametrize('a,b,expected', [(6,3,2), (5,2,2.5)], ids=['int','float'])
def test_div(a, b, expected):
    assert a / b == expected

@pytest.mark.skip(reason='not needed today')
def test_skipped():
    pass

@pytest.mark.xfail(reason='known bug')
def test_xfail():
    assert False
```

## Fixture Scopes and Autouse

```python
import pytest

@pytest.fixture(scope='session')
def config():
    return {'base_url': 'https://www.saucedemo.com/'}

@pytest.fixture(autouse=True)
def ensure_clean_env(monkeypatch):
    monkeypatch.delenv('MY_VAR', raising=False)
```

## Selenium Driver Fixture (conftest template)

```python
# tests/conftest.py
import pytest
from selenium import webdriver

@pytest.fixture
def driver():
    drv = webdriver.Chrome()
    try:
        yield drv
    finally:
        drv.quit()
```

## Page Object Model (POM)

```python
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

class LoginPage:
    URL = 'https://www.saucedemo.com/'
    USER = (By.ID, 'user-name')
    PASS = (By.ID, 'password')
    BTN  = (By.ID, 'login-button')

    def __init__(self, driver):
        self.driver = driver

    def open(self):
        self.driver.get(self.URL)

    def login(self, u, p):
        wait = WebDriverWait(self.driver, 10)
        wait.until(EC.visibility_of_element_located(self.USER)).send_keys(u)
        wait.until(EC.visibility_of_element_located(self.PASS)).send_keys(p)
        wait.until(EC.element_to_be_clickable(self.BTN)).click()
```

## Production Logging (dictConfig)

```python
import logging, logging.config

LOGGING = {
  'version': 1,
  'disable_existing_loggers': False,
  'formatters': {
    'std': {'format': '%(asctime)s [%(levelname)s] %(name)s: %(message)s'},
  },
  'handlers': {
    'console': {'class': 'logging.StreamHandler', 'formatter': 'std'},
    'file': {
      'class': 'logging.handlers.RotatingFileHandler',
      'filename': 'app.log', 'maxBytes': 1048576, 'backupCount': 3,
      'formatter': 'std'
    }
  },
  'root': {'level': 'INFO', 'handlers': ['console', 'file']}
}

logging.config.dictConfig(LOGGING)
logger = logging.getLogger(__name__)
logger.info('configured')
```

## Useful `expected_conditions`

- `visibility_of_element_located`
- `element_to_be_clickable`
- `presence_of_all_elements_located`
- `url_contains`, `title_contains`

## Pytest CLI Tips

- Parallel (requires xdist): `pytest -n auto`
- Live logs: `pytest --log-cli-level=INFO`
- Filter by keyword: `pytest -k login`
