(ns test.core (:gen-class))

(require '[clojure.tools.cli :refer [cli]])

(use 'serial.core)

(def arduinoPort "COM5")

(defn prepare6byte [temperature]
  (+ 0x79 temperature))

(defn prepareBinaryData [temperature]
   (vector 0xC4 0xD3 0x64 0x84 0x00 0x02 0x22 0x8C 0x20 0x00 0x00 0xFD 0x73 0x73 0xDF 0xFF 0xFF))

(defn setTemp [temperature]
  (println "setTemp start")
  (def port (open arduinoPort))
  (write port (prepareBinaryData temperature))
  (close! port)
  (println "setTemp end"))


(defn -main []
  (println "Hello, World!")
  (setTemp 19))


