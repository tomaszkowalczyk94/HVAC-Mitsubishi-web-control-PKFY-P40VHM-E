(ns test.core (:gen-class))

(require '[clojure.tools.cli :refer [cli]])

(defn -main []  (println "Hello, World!"))



;(use 'serial.core)
;(defn foo
;  "I don't do a whole lot."
;  [x]
;  (println x "Hello, World!"))
;
;(def port (open "COM5"))
;(listen! port (fn [stream] (println stream)), false)
;
;(delay 9999999)
