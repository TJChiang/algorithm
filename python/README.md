# algorithm-python

## 開發環境

### Docker 執行環境

1. 進入 container 執行 python

```bash
docker compose run --rm -it python bash
```

2. 建立虛擬環境

```bash
python3 -m venv .venv
```

3. 啟動虛擬環境

```bash
source .venv/bin/activate
```

4. pip 安裝 packages

```bash
pip install ...
pip install -r requirements.txt
```

5. 關閉 venv

```bash
deactivate
```

### Docker 開發環境

`cmd + shift + P` 輸入 `Dev Containers: Open Folder in Container...` ，選擇 python
