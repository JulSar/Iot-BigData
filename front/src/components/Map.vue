<template>
  <div id="mapid"></div>
</template>

<script>
  import L from 'leaflet';
  import { mapGetters, mapActions } from 'vuex';

  export default {
    name: 'Map',
    data() {
      return {
        map: undefined,
        markers: [],
      };
    },
    mounted() {
      this.map = L.map('mapid', {
        center: this.intensities.length ?
          [this.intensities[0].lat, this.intensities[0].lng] : [48.866667, 2.333333],
        zoom: 12,
      });
      L.tileLayer('http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {}).addTo(this.map);
      setInterval(this.addIntensities, 5000);
    },
    computed: {
      ...mapGetters([
        'intensities',
      ]),
    },
    watch: {
      intensities() {
        this.addMarkers();
      },
    },
    methods: {
      ...mapActions([
        'addIntensities',
      ]),
      addMarkers() {
        const { intensities } = this;
        if (!intensities) return [];

        if (this.markers) {
          this.markers.forEach(marker => marker.remove());
        }

        return intensities.map((intensity) => {
          const marker = this.getMarker(intensity);
          marker.bindTooltip(intensity.value.toString());
          marker.addTo(this.map);
          return marker;
        });
      },
      getMarker(intensity) {
        let icon;
        if (intensity.value < 40) {
          icon = L.icon({
            iconUrl: 'https://raw.githubusercontent.com/pointhi/leaflet-color-markers/master/img/marker-icon-2x-green.png',
            iconSize: [25, 41],
            iconAnchor: [12, 41],
            popupAnchor: [1, -34],
          });
        } else if (intensity.value < 65) {
          icon = L.icon({
            iconUrl: 'https://raw.githubusercontent.com/pointhi/leaflet-color-markers/master/img/marker-icon-2x-yellow.png',
            iconSize: [25, 41],
            iconAnchor: [12, 41],
            popupAnchor: [1, -34],
          });
        } else {
          icon = L.icon({
            iconUrl: 'https://raw.githubusercontent.com/pointhi/leaflet-color-markers/master/img/marker-icon-2x-red.png',
            iconSize: [25, 41],
            iconAnchor: [12, 41],
            popupAnchor: [1, -34],
          });
        }
        return L.marker({ lat: intensity.lat, lng: intensity.lng }, { icon });
      },
    },
  };
</script>

<style>
  #mapid {
    height: 800px;
  }
</style>
