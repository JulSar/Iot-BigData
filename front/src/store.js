import Vue from 'vue';
import Vuex from 'vuex';
import rp from 'request-promise';

Vue.use(Vuex);

const server = 'http://51.15.208.245:5000';

async function getIntensities() {
  const response = await rp.get(`${server}/retrieve_all_wifi`, { json: true });
  return response.data.map(intensity => ({
    lat: intensity.lat,
    lng: intensity.lng,
    value: intensity.signal_strength,
  }));
}

export default new Vuex.Store({
  state: {
    intensities: [],
  },
  mutations: {
    addWifi(state, intensities) {
      state.intensities = intensities;
    },
  },
  actions: {
    async addIntensities({ commit }) {
      const intensities = await getIntensities();
      commit('addWifi', intensities);
    },
  },
  getters: {
    intensities(state) {
      return state.intensities;
    },
  },
});
