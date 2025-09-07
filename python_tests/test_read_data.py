"""Python-file for testing class ReadData"""

from intersection import ReadData


def test_read_data():
    """Funktion zum Testen von ReadData"""
    read_data = ReadData("./data/supermarkt_0/produkte.txt")
    read_data.read_txt()
    assert read_data.read_txt() is not None
    with open("./data/supermarkt_0/produkte.txt", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert read_data.read_txt() == file_content
    read_data.display_data()

    assert read_data.observe_cache() is None
    read_data.observe_cache()
    try:
        read_data.display_data()
    except RuntimeError as e:
        print(f"Ausnahme erkannt: {e}")

    csv_data = ReadData("./data/numbers.csv")
    csv_data.read_csv()
    csv_data.display_data()
    assert csv_data.read_csv() is not None
    with open("./data/numbers.csv", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert csv_data.read_csv() == file_content

    csv_data.display_data()

    assert csv_data.observe_cache() is None
    csv_data.observe_cache()
    try:
        csv_data.display_data()
    except RuntimeError as e:
        print(f"Ausnahme erkannt: {e}")

    json_data = ReadData("./.vscode/settings.json")
    json_data.read_json()
    assert json_data.read_json() is not None
    with open("./.vscode/settings.json", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert json_data.read_json() == file_content

    with open("README.pdf", "rb") as f:
        content = f.read()
        assert len(content) > 0

    json_data.display_data()

    assert json_data.observe_cache() is None
    json_data.observe_cache()
    try:
        json_data.display_data()
    except RuntimeError as e:
        print(f"Ausnahme erkannt: {e}")

    auto_data = ReadData("logfile.txt")
    auto_data.read_auto(False)
    assert auto_data.read_auto(False) is not None
    with open("logfile.txt", "r", encoding="utf-8") as f:
        file_content = f.read()
        assert auto_data.read_auto(False) == file_content

    auto_data.display_data()

    assert auto_data.observe_cache() is None
    auto_data.observe_cache()
    try:
        auto_data.display_data()
    except RuntimeError as e:
        print(f"Ausnahme erkannt: {e}")

    haendler = ReadData("./data/supermarkt_0/haendler.txt")
    haendler.read_txt()
    data_set = haendler.display_data()
    print(data_set[0:10])
    haendler.observe_cache()

    assert haendler.observe_cache() is None
    try:
        haendler.display_data()
    except RuntimeError as e:
        print(f"Ausnahme erkannt: {e}")

    html_reader = ReadData("./data/example.html")
    html_reader.read_html()
    html_data_set = html_reader.display_data()
    print(html_data_set[0:2])
    html_reader.observe_cache()

    assert html_reader.observe_cache() is None
    try:
        html_reader.display_data()
    except RuntimeError as e:
        print(f"Ausnahme erkannt: {e}")

    xml_reader = ReadData("./data/example.xml")
    xml_reader.read_xml()
    xml_data_set = xml_reader.display_data()
    print(xml_data_set[0:2])
    xml_reader.observe_cache()

    assert xml_reader.observe_cache() is None
    try:
        xml_reader.display_data()
    except RuntimeError as e:
        print(f"Ausnahme erkannt: {e}")


test_read_data()
