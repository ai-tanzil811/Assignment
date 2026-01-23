# Selenium + Pytest Cheat Sheet

## Locators

- By ID: `By.ID, 'login-button'`
- By Class: `By.CLASS_NAME, 'inventory_item'`
- CSS: `By.CSS_SELECTOR, '.inventory_item_name'`
- XPATH: `By.XPATH, "//div[@class='inventory_item']"`

## Waits (Explicit)

```python
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
wait = WebDriverWait(driver, 10)
wait.until(EC.visibility_of_element_located((By.ID, 'user-name')))
wait.until(EC.element_to_be_clickable((By.ID, 'login-button')))
wait.until(EC.url_contains('inventory'))
```

## Common Patterns

- Prefer explicit waits over `time.sleep`.
- Wrap driver usage in `try/finally` and always `quit()`.
- POM: Keep selectors in classes.

## Pytest Essentials

- File names: `test_*.py` or `*_test.py`
- Function names: `test_*`
- Fixtures in `conftest.py`, example `driver` fixture.

## CLI

- Run all: `pytest -v`
- Filter: `pytest -k login`
- Live logs: `pytest --log-cli-level=INFO`
